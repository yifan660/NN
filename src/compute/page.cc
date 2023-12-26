#include <memory>

// AC means assembly combine
#define PAGE_OFFSET         _AC(CONFIG_PAGE_OFFSET, UL)
#define PAGE_SHIFT          (12)
#define PAGE_SIZE           (_AC(1, UL) << PAGE_SHIFT)
#define PAGE_MASK           (~(PAGE_SIZE - 1))

#define HPAGE_SHIFT         PMD_SHIFT
#define HPAGE_SIZE          (_AC(1, UL) << HPAGE_SHIFT)
#define HPAGE_MASK          (~(HPAGE_SIZE-1))
#define HUGETLB_PAGE_ORDER  (HPAGE_SHIFT-PAGE_SHIFT)

#ifdef CONFIG_64BIT
#ifdef CONFIG_MMU
#define PAGE_OFFSET         kernel_map.page_offset
#define PTE_FMT "%08lx"#else

#define PAGE_OFFSET         _AC(CONFIG_PAGE_OFFSET, UL)
#endif

#define PAGE_OFFSET_L4      _AC(0xffffaf8000000000, UL)
#define PAGE_OFFSET_L3      _AC(0xffffffd800000000, UL)
#else
#define PAGE_OFFSET         _AC(CONFIG_PAGE_OFFSET, UL)
#endif


#ifdef CONFIG_RISCV_ISA_ZICBOZ
#define phys_to_pfn(phys)       (PFN_DOWN(phys))
#define pfn_to_phys(pfn)        (PFN_PHYS(pfn))

#define virt_to_pfn(vaddr)      (phys_to_pfn(__pa(vaddr)))
#define pfn_to_virt(pfn)        (__va(pfn_to_phys(pfn)))

#define virt_to_page(vaddr)     (pfn_to_page(virt_to_pfn(vaddr)))
#define page_to_virt(page)      (pfn_to_virt(page_to_pfn(page)))

#define
#define

#define
#define
#define

void clear_page(void* page);

#define clear_page(pgaddr)      memset((pgaddr), 0, )
#define copy_page(to, from)     memcpy((to), (from), PAGE_SIZE)

#define clear_user_page(pgaddr, vaddr, page)    clear_page(pgaddr)
#define copy_user_page(vto, vfrom, vaddr, topg) memcpy((vto), (vfrom), PAGE_SIZE)

typedef struct {
    unsigned long pgd;
} pgd_t;

typedef struct {
    unsigned long pte;
} pte_t;

typedef struct {
    unsigned long pgprot;
} pgprot_t;

typedef struct page *pgtable_t;

#define pte_val(x)      ((x).pte)
#define pgd_val(x)      ((x).pgd)
#define pgprot_val(x)   ((x).pgprot)

#define __pte(x)        ((pte_t) { (x) })
#define __pgd(x)        ((pgd_t) { (x) })
#define __pgprot(x)     ((pgprot_t) { (x) })

#ifdef CONFIG_64BIT
#define PTE_FMT "%016lx"
#else
#define PTE_FMT "%08lx"


struct kernel_mapping   {
    unsigned long page_offset;
    unsigned long virt_addr;
    unsigned long virt_offset;
    uintptr_t phys_addr;
    uintptr_t size;
    unsigned long va_pa_offset;
    unsigned long va_kernel_pa_offset;
    unsigned long va_kernel_xip_pa_offset;
#ifdef CONFIG_XIP_KERNEL

};

#define is_kernel_mapping(x)    ((x)>=kernel_map.virt_addr && (x) < (kernel_map.virt_addr+kernel_map.size))
#define is_linear_mapping(x)    ((x)>=PAGE_OFFSET && (!IS_ENABLED(CONFIG_64BIT) || (x)<PAGE_OFFSET+KERN_VIRT_SIZE))

#ifndef CONFIG_DEBUG_VIRTUAL
#define linear_mapping_pa_to_va(x)
#else
void *linear_mapping_pa_to_va(unsigned long x);
#define

#define PMD_SIZE        12
#define PTRS_PER_PMD    128     // for 64 bit system PTRS_PER_

#define PMD_MASK

arch/riscv/include/
asmlinkage unsigned long sys_brk()  {
    unsigned long rlim, retval;
    unsigned long newbrk, oldbrk;
    struct mm_struct *mm = current->mm;

    down(&mm->mmap_sem);

    if(brk<mm->end_code)    {
        goto out;
    }
    newbrk = PAGE_ALIGN(brk);
    oldbrk = PAGE_ALIGN(mm->brk);
    if(oldbrk==newbrk)  {
        goto set_brk;
    }
    /* Always allow shrinking brk. */
    if(brk<=mm->brk)    {
        if(!do_munmap(mm, newbrk, oldbrk-newbrk))   {
            goto set_brk;
        }
        goto out;
    }
}


struct vm_area_struct
{
    int vm_start;
    int vm_end;
};

int do_munmap(struct mm_struct *mm, unsigned long addr, size_t len) {
    struct vm_area_struct *mpnt, *prev, **npp, *free, *extra;

    if((addr&~PAGE_MASK)||addr>TASK_SIZE||len>TASK_SIZE-addr)    {
        return -EINVAL;
    }
    if((len=PAGE_ALIGN(len))==0)    {
        return -EINVAL;
    }
    mpnt = find_vma_prev(mm, addr, &prev);  // find block whose end address is greater than given address
    if(!mpnt)   {
        return 0;
    }
    if(mpnt->vm_start>=addr+len)    {
        return 0;
    }
    if(mnpt->vm_start<addr&&mnpt->vm_end>addr+len)

    while((mpnt=free)!=NULL)    {
        unsigned long st, end, size;
        struct file *file = NULL;

        free = free->vm_next;
        st = addr < mpnt->vm_start ? mpnt->vm_start : addr;
        end = addr+len;
        end = end>mpnt->vm_end?mpnt->vm_end:end;
        size = end-st;
}
}


void zap_page_range(struct mm_struct *mm, unsigned long address, unsigned long size)   {
    pgd_t *dir;
    unsigned long end = address+size;
    int freed = 0;

    dir = pgd_offset(mm, address);
    if(address>=end)    {
        ASSERT();
    }
    spin_lock(&mm->page_table_lock);
    do  {
        freed += zap_pmd_range()
        address = (address+PGDIR_SIZE) & PGDIR_MASK;
        dir++; 
    } while(address&&(address<end));
    spin_unlock(&mm->page_table_lock);
    if(mm->rss>freed)   {
        mm->rss-=freed;
    } else  {
        mm->rss=0;
    }
}

#define pgd_index(address)      ((address>>PGDIR_SHIFT)&(PTRS_PER_PGD-1))
#define __pgd_offset(address)   pgd_index(address)
#define pgd_offset(mm, address) ((mm)->pgd+pgd_index(address))

static inline int zap_pmd_range(struct mm_struct *mm, pgd_t *dir, unsigned long address, unsigned long size)    {
    pmd_t *pmd;
    unsigned long end;
    int freed;

    if(pgd_none(*dir))  {
        return 0;
    }
    if(pgd_bad(*dir))   {
        pgd_ERROR(*dir);
        pgd_clear(dir);
        return 0;
    }
    pmd = pmd_offset(dir, address);
    address &= ~PGDIR_MASK;
    end = address+size;
    if(end>PGDIR_SIZE)  {
        end = PGDIR_SIZE;
    }
    freed = 0;
    do  {
        freed+=zap_pte_range(mm, pmd, address, end-address);
        address=(address+PMD_SIZE) & PMD_MASK;
        pmd++;
    } while(address<end);
    return freed;
}

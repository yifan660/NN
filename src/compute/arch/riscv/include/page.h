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
#define linear_mapping_pa_to_va(x)      ((void *)((unsigned long)(x)+kernel_map.va_pa_offset))
#else
void *linear_mapping_pa_to_va(unsigned long x);
#endif

#define kernel_mapping_pa_to_va(y)  ({
        unsigned long _y = (unsigned long)(y);
        (IS_ENABLED(CONFIG_XIP_KERNEL) && _y < phys_ram_base) ?
                (void *)(_y+kernel_map.va_kernel_xip_pa_offset) :
                (void *)(_y+kernel_map.va_kernel_pa_offset+XIP_OFFSET);
        })

#define __pa_to_va_nodebug(x)           linear_mapping_pa_to_va(x)

#ifndef CONFIG_DEBUG_VIRTUAL
#define linear_mapping_va_to_pa(x)      ((unsigned long)(x)-kernel_map.va_pa_offset) 
#else
phys_addr_t linear_mapping_va_to_pa(unsigned long x);
#endif

#define kernel_mapping_va_to_pa(y)  ({
        unsigned long _y = (unsigned long)(y);
        (IS_ENABLED(CONFIG_XIP_KERNEL) && _y < kernel_map.virt_addr+XIP_OFFSET) ?
                (_y-kernel_map.va_kernel_xip_pa_offset) :
                (_y-kernel_map.va_kernel_pa_offset-XIP_OFFSET);
        })

#define __va_to_pa_nodebug(x)   ({
        unsigned long _x = x;
        is_linear_mapping(_x) ?
                linear_mapping_va_to_pa(_x) : kernel_mapping_va_to_pa(_x);
        })

#ifdef CONFIG_DEBUG_VIRTUAL
#define phys_to_pfn(phys)       (PFN_DOWN(phys))
#define pfn_to_phys(pfn)        (PFN_PHYS(pfn))

#define virt_to_pfn(vaddr)      (phys_to_pfn(__pa(vaddr)))
#define pfn_to_virt(pfn)        (__va(pfn_to_phys(pfn)))

#define virt_to_page(vaddr)     (pfn_to_page(virt_to_pfn(vaddr)))
#define page_to_virt(page)      (pfn_to_virt(page_to_pfn(page)))

#define virt
#define

#define
#define
#define

#ifdef CONFIG_MMU

#define GFP_PGTABLE_KERNEL      (GFP_KERNEL | __GFP_ZERO)
#define GFP_PGTABLE_USER        (GFP_PGTABLE_KERNEL | __GFP_ACCOUNT)

static inline pte_t *__pte_alloc_one_kernel(struct mm_struct *mm)   {
    struct ptdesc *ptdesc = pagetable_alloc(GFP_PGTABLE_KERNEL & ~__GFP_HIGHMEM, 0);

    if(!ptdesc) {
        return NULL;
    }
    if(!pagetable_pte_ctor(ptdesc)) {
        pagetable_free(ptdesc);
        return NULL;
    }

    return ptdesc_page(ptdesc);
}


static inline void pte_free(struct mm_struct *mm, struct page *pte_page)    {
    struct ptdesc *ptdesc = page_ptdesc(pte_page);

    pagetable_pte_dtor(ptdesc);
    pagetable_free(ptdesc);
}


#if CONFIG_PGTABLE_LEVELS > 2

#ifndef __HAVE_ARCH_PMD_ALLOC_ONE

static inline pmd_t *pmd_alloc_one(struct mm_struct *mm, unsigned long addr)    {
    struct ptdesc *ptdesc;
    gfp_t gfp = GFP_PGTABLE_USER;

    if(mm==&init_mm)    {
        gfp = GFP_PGTABLE_KERNEL;
    }
    ptdesc = pagetable_alloc(gfp, 0);
    if(!ptdesc)    {
        return NULL;
    }
    if(!pagetable_pmd_ctor(ptdesc))    {
        pagetable_free(ptdesc);
        return NULL;
    }
    return ptdesc_address(ptdesc);
}
#endif


#ifndef __HAVE_ARCH_PMD_FREE
static inline void pmd_free(struct mm_struct *mm, pmd_t *pmd)   {
    struct ptdesc *ptdesc = virt_to_ptdesc(pmd);

    BUG_ON((unsigned long)pmd & (PAGE_SIZE-1));

}


static inline void __pud_free() {
    
}

static inline

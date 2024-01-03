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

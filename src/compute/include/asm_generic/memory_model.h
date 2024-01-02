#ifndef ARCH_PFN_OFFSET 
#define ARCH_PFN_OFFSET     (0UL)
#endif

#define __pfn_to_page(pfn)      (mem_map+((pfn)-ARCH_PFN_OFFSET))
#define __page_to_pfn(page)     ((unsigned long)((page)-mem_map)+ARCH_PFN_OFFSET)

#ifndef pfn_valid 
static inline int pfn_valid(unsigned long pfn)  {
    extern unsigned long max_mapnr;
    unsigned long pfn_offset = ARCH_PFN_OFFSET

    return pfn_offset >= pfn_offset && (pfn-pfn_offset)<max_mapnr;
}

#define
#define __page_to_pfn(pfn)      ((vmemmap+(pfn)))
#define __pfn_to_page(page)     ((page-vmemmap)) 

#elif defined(CONFIG_SPARSEMEM)
#define __page_to_pfn()
({  const struct page *__pg = (pg);
    int __sec = page_to_section(__pg);
    (unsigned long)(__pg - __section_mem_map_addr(__nr_to_section(__sec)));
})
#define __pfn_to_page()
({
    unsigned long __pfn = (pfn);
    struct mem_section *__sec = __pfn_to_section(__pfn);
    __section_mem_map_addr(__sec) + __pfn;
})

#define
#define

#define phys_to_pfn(paddr)      PHYS_PFN(paddr)
#define pfn_to_phys(pfn)        PFN_PHYS(pfn)

#define page_to_pfn
#define pfn_to_page

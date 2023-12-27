#ifndef 
#define


#include 
#include
#include
#include
#include
#include


#ifndef tlb_needs_table_invalidate
struct mmu_table_batch  {
#ifdef CONFIG_MMU_GATHER_RCU_TABLE_FREE
    struct rcu_head rcu;
#endif
    unsigned int    nr;
    void            *tables[];    
};

#define MAX_TABLE_BATCH     ((PAGE_SIZE-sizeof(struct mmu_table_batch))/sizeof(void *))

extern void tlb_remove_table(struct mmu_gather *tlb, void *table);

#else

#define tlb_remove_table(tlb, page) tlb_remove_page((tlb), (page))

#endif

#ifdef CONFIG_MMU_GATHER_RCU_TABLE_FREE

#ifndef tlb_needs_table_invalidate
#define tlb_needs_table_invalidate()    (true)
#endif

void tlb_remove_table_sync_one(void);

#else

#ifdef tlb_needs_table_invalidate
#error tlb_needs_table_invalidate() requires MMU_GATHER_RCU_TABLE_FREE
#endif

static inline void tlb_remove_table_sync_one(void)  { }



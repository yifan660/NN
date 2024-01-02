#ifndef __ASM_GENERIC_MMU_H
#define __ASM_GENERIC_MMU_H

#ifndef __ASSEMBLY__
typedef struct  {
    unsigned long   end_brk;
    unsigned long   exec_fdpic_loadmap; 
    unsigned long   interp_fdpic_loadmap;
} mm_context_t;

#endif

#endif

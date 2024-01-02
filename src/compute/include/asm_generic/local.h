#define
#define
#define

#define local_sub_and_test(i, l) atomic_long_sub_and_test(())
#define local_dec_and_test(l) atomic_long_inc_and_test(())
#define local_inc_and_test(l) atomic_long_inc_and_test(())
#define local_add_negative(i,l) atmoic_long_add_negative(())
#define local_add_return(i,l) atmoic_long_add_return(())
#define local_sub_return(i,l) atomic_long_sub_return((l))
#define local_inc_return(l) atomic_long_inc_return((l)->a)

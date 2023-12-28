static inline int generic_atomic_##op(int i, atomic_t *v)   
{
    int c, old;

    c = v->counter;
    while((old=arch_cmpxchg(&v->counter, c, c c_op i))!=c)  {
        c = old;
    }
}

static inline int generic_atomic_##op##_return(int i, atomic_t *v)  {
    int c, old;

    c = v->counter;
    while((old=arch_cmpxchg(&v->counter, c, c c_op i))!=c)  {
        c = old;
    }
    return c c_op i;
}

static inline int generic_atomic_fetch_##op(int i, atomic_t *v) {
    int c, old;

    c = v->counter;
    while((old=arch_cmpxchg(&v->counter, c, c c_op i))!=c)  {
        c = old;
    }
    return c c_op i;
}

static inline int generic_atomic_fetch_##op(int i, atomic_t *v) {
    unsigned long flags;
    int ret;

    raw_local_irq_save(flags);
    ret = v->counter;
    v->counter = v->counter c_op i;
}

ATOMIC_OP_RETURN
ATOMIC_OP_RETURN

ATOMIC_FETCH_OP(add, +)
ATOMIC_FETCH_OP(sub, -)
ATOMIC_FETCH_OP(and, &)
ATOMIC_FETCH_OP(or, |)
ATOMIC_FETCH_OP(xor, ^)

ATOMIC_OP(add, +)
ATOMIC_OP(sub, -)
ATOMIC_OP(and, &)
ATOMIC_OP(or, |)
ATOMIC_OP(xor, ^)

#undef

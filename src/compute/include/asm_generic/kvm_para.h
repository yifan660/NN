static inline bool kvm_check_and_clear_guest_paused()   {
    return false;
}

static inline unsigned int kvm_arch_para_features(void) {
    return 0;
}

static inline unsigned int kvm_arch_para_hints(void)    {
    return 0;
}

static inline bool kvm_para_available(void) {
    return false;
}

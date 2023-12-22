#include <fstream>
#include <array>
#include <memory>
#include <unordered_map>
#include <map>
#include <algorithm>
#include <vector>
#include <cstring>
#include <random>
#include <cassert>
#include <cstring>
#include <thread>
#include <mutex>
#include <c>

#include ""
#include ""
#include ""
#include ""

void kv_cache_init() {

}

class Object    {
  public:
    
};

enum e_model {
    MODEL 
    MODEL 
    MODEL 
    MODEL 

};

enum 
struct kv_

static const size_t KB  1024;
static const size_t MB  1024*1024;

static const std::map<e_model, size_t> & MEM_REQ_EVAL(int n_ctx)  {
    static std::map<e_model, size_t> k_sizes = {
        {MODEL, ((size_t)n_ctx/16+92)*MB},
        {MODEL, (size_t)n_ctx/16+100)*MB},
        {MODEL, (size_t)n_ctx/12+120)*MB},
        {MODEL, (size_t)n_ctx/9+160)*MB},
        {MODEL, (size_t)n_ctx/6+256)*MB},
    };
    return k_sizes;
}

static const std::map<> & MEM_REQ_EVAL1()   {
    static std::map<e_model, size_t> k_sizes = {
        {MODEL, (128)*MB},
        {MODEL, (160)*MB},
        {MODEL, (192)*MB},
        {MODEL, (256)*MB},
        {MODEL, (384)*MB},
    };
    return k_sizes;
}

static const std::map<> & MEM_REQ_EVAL2()   {
    static std::map<e_model, size_t> k_sizes = {
        {, (12)},
        {, ()},
        {, ()},
        {, ()},
        {, ()},
        {, ()},
    };
}

static const std::map<> & MEM_REQ_EVAL3()   {
    static std::map<> k_sizes = {
        {, ()},
        {, ()},
        {, ()},
        {, ()},
        {, ()},
        {, ()},
    };
};

struct stable_diffusion_hparams {
    uint32_t n_vocab = 32000;
    uint32_t n_ctx = 512;
    uint32_t n_embd = 4096;
    uint32_t n_mult = 256;
    uint32_t n_head = 32;
    uint32_t n_head_kv = 32;
    uint32_t n_layer = 32;

    bool operator!()    {
        return static_cast<>
    }

    n_gqa() {
        return n_head/n_head_kv;
    }

    n_embd_head()   {
        return n_embd/n_head;
    }

    n_embd_gqa()    {
        return n_embd/n_gqa;
    }

    kv_size()   {
        size_t result = ;
        result *= (size_t)
        result *= (size_t) n_ctx;
        result *= (size_t) n_layer;
        result *= (sizeof)(icl_fp16_t);

        return result;
    }
};


struct stable_diffusion_layer   {
    struct Tensor *wq;
    struct Tensor *wk;
    struct Tensor *wv;
    struct Tensor *;

    struct Tensor *;   

    struct Tensor *w1;
    struct Tensor *w2;
    struct Tensor *w3;
    
};


std::vector<stable_diffusion_layer>
struct stable_diffusion_kv_cache    {
    struct Tensor *k;
    struct Tensor *v;
    struct Tensor *;
    struct Tensor *;

};


struct stable_diffusion_vocab   {
    using id = int;
    using token = std::string;
    using image = std::vector<int>;
    using 
    using 
    using 
    using
    using

    std::unordered_map<>

    struct tok  {
        size_t 
        size_t
        size_t
    };

    struct token_score  {
        token tok;
        float score;
    };
};



struct stable_diffusion_model   {
    Tensor *wq;
    Tensor *wk;
    Tensor *
    ~stable_diffusion_model()   {
        tensor.free();
    }
    stable_diffusion_model()    {
        delete model;
    }
};

struct stable_diffusion_context {
    stable_diffusion_context()  {
        int32_t
        int32_t
        int32_t
        int32_t
    }
    ~stable_diffusion_context();

};

// allreduce operator
void ccl.allreduce() {
    cyclic connection
}

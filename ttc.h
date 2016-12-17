#ifndef TTC_C_H
#define TTC_C_H

namespace ttc {

typedef struct node{
   int start;
   int end;
   int inc;
   int lda;
   int ldb;
   node *next = nullptr;
} node_t;

typedef struct plan{
   int numThreads;
   node_t **localPlans = nullptr;
} plan_t;

plan_t* createPlan(const int *lda, const int *ldb, const int *size, const int* perm, const int dim, const int numThreads);

void sTranspose( const float* __restrict__ A, float* __restrict__ B, const float alpha, const float beta, plan_t *plan);

void trashCache(double *A, double *B, int n);

}

#endif

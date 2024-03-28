
//
// base_thread_context.h
//
// Caleb Barger
// 03/27/24 
//

#ifndef BASE_THREAD_CONTEXT_H

typedef struct ThreadCTX ThreadCTX;
struct ThreadCTX {
  Arena* arena;     
};

internal void thread_ctx_init(ThreadCTX* thread_ctx); 
internal inline Temp temp_begin(); 
internal inline void temp_end(Temp temp); 

#define BASE_THREAD_CONTEXT_H
#endif

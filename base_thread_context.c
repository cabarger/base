//
// base_thread_context.c
//
// Caleb Barger
// 03/27/24 
//

__thread ThreadCTX* local_thread_ctx;

internal void thread_ctx_init(ThreadCTX* thread_ctx) {
  if (thread_ctx == nil) {
    InvalidPath;
  }
  thread_ctx->arena = arena_alloc();
  local_thread_ctx = thread_ctx;
}

internal inline Temp temp_begin() {
  if (local_thread_ctx == nil) {
    AssertMessage("No thread context initialized");
  }
  return scratch_begin(local_thread_ctx->arena);
}

internal inline void temp_end(Temp temp) {
  scratch_end(temp);
}

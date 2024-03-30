//
// base_string.c
//
// Caleb Barger
// 02/11/24 
//

internal String8 str8_cat(Arena* arena, String8 a, String8 b) {
  String8 result;
  result.str = arena_push(arena, a.len + b.len);
  result.len = 0;

  for (U64 a_index=0; a_index < a.len; ++a_index)
    result.str[result.len++] = a.str[a_index];
  for (U64 b_index=0; b_index < b.len; ++b_index)
    result.str[result.len++] = b.str[b_index];

  return result;
}

internal String8 str8_from_memz(U8* str) {
  String8 result;
  U64 s_len = 0;
  {
    U8* curr_ptr = str;
    for (; *curr_ptr != '\0'; ++curr_ptr) {} 
    s_len = (U64)(curr_ptr - str);
  } 
  result.str = str;
  result.len = s_len;
  return result;
}

internal String8 str8_sub(String8 str, U64 start, U64 end) {
  String8 result;
  result.str = (U8*)str.str + start;
  result.len = end - start;
  return result;
}

internal String8 str8_copy(Arena* arena, String8 source) {
  String8 dest = {
    .str = (U8*)arena_alloc(arena, source.len),
    .len = source.len,
  };
  for (U64 source_index=0; source_index < source.len; ++source_index)
    dest.str[source_index] = source.str[source_index];
  return dest;
}

internal B8 str8_eql(String8 a, String8 b) {
  B8 result = 0;
  if (a.len == b.len) {
    result = (memcmp(a.str, b.str, a.len) == 0);
  }
  return result;
}

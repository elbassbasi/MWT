/*
 *  utf8.h
 *
 *  Created on: 22-07-2023
 *  Author: azeddine El Bassbasi
 */

#ifndef MWT_CORE_UTF8_H_
#define MWT_CORE_UTF8_H_
#include "defs.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef size_t (*m_alloc)(void *user_data, size_t size, void **buf);
MEXPORT MResult m_alloc_set_text(m_alloc alloc, void *user_data,
		const char *text, size_t length);

typedef struct MAllocBuffer {
	void *buffer;
	size_t size;
	size_t total_size;
} MAllocBuffer;
size_t m_alloc_buffer_new(void *user_data, size_t size, void **buffer);
size_t m_alloc_buffer_copy(void *user_data, size_t size, void **buffer);
enum {
	MENCODING_UTF8 = 0, MENCODING_UNICODE, MENCODING_PLATFORM,
};
typedef struct m_utf8_char {
	MUInt char32;
	MWChar char16[2];
	int char16_length;
} m_utf8_char;
/*
 * utf8 string
 */
#define M_UTF8_ATTNDS
typedef struct m_utf8_iter {
	const char *p;
	MUInt utf32;
	MWChar utf16;
	short flags;
} m_utf8_iter;
MEXPORT extern const char w_utf8_skip_data[256];
MEXPORT void m_utf8_iter_init(m_utf8_iter *iter, const char *p);
MEXPORT MUnichar m_utf8_iter_next_utf32(m_utf8_iter *iter);
MEXPORT MWChar m_utf8_iter_next_utf16(m_utf8_iter *iter);
MEXPORT MUnichar m_utf8_get_unichar(const char *p);
MEXPORT int m_utf8_get_wchars(const char *p, MWChar *wchars);
MEXPORT MUnichar m_utf8_get_char_extended(const char *p, int max_len);
MEXPORT MUnichar m_utf8_get_next_char(const char *p, const char **next);
MEXPORT const char* m_utf8_find_prev(const char *str, const char *p);
MEXPORT const char* m_utf8_find_next(const char *p, const char *end);
MEXPORT const char* m_utf8_prev(const char *p);
MEXPORT const char* m_utf8_next(const char *p);
MEXPORT const char* m_utf8_next_unichar(const char *p, MUnichar *_unichar);
MEXPORT const char* m_utf8_next_wchars(const char *p, MWChar *wchars);
MEXPORT size_t m_utf8_strlen(const char *p, size_t max);
MEXPORT char* m_utf8_offset_to_pointer(const char *str, int offset);
MEXPORT int m_utf8_pointer_to_offset(const char *str, const char *pos);
MEXPORT char* m_utf8_strncpy(char *dest, const char *src, int n);
MEXPORT int m_utf8_from_unichar(int c, char *outbuf);
MEXPORT char* m_utf8_strchr(const char *p, int c);
MEXPORT int m_utf8_from_utf16(const MWChar *str, int len, char *result,
		int n);
MEXPORT int m_utf8_to_utf16(const char *str, int len, MWChar *result, int n);
MEXPORT int m_utf8_from_ucs4(const MWChar *str, int len, char *result, int n);
MEXPORT int m_utf8_to_ucs4(const char *str, int len, MUnichar *result,
		int n);
MEXPORT char* m_strndup(const char *s, size_t n);
#ifdef __cplusplus
}
#endif
#endif /* MWT_CORE_UTF8_H_ */

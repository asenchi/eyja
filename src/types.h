/*
 * Copyright (c) 2012, Curt Micol <asenchi@asenchi.com>
 *
 * Permission to use, copy, modify, and/or distribute this software for
 * any purpose with or without fee is hereby granted, provided that the
 * above copyright notice and this permission notice appear in all
 * copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL
 * WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE
 * AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL
 * DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR
 * PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER
 * TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR
 * PERFORMANCE OF THIS SOFTWARE.
 */

#ifndef TYPES_H
#define TYPES_H

typedef enum {
        NIL, BOOLEAN, SYMBOL, FIXNUM, CHARACTER, STRING, PAIR
} object_type;

typedef struct object {
        object_type type;
        union {
                struct {
                        char value;
                } boolean;
                struct {
                        char *value;
                } symbol;
                struct {
                        long value;
                } fixnum;
                struct {
                        char value;
                } character;
                struct {
                        char *value;
                } string;
                struct {
                        struct object *car;
                        struct object *cdr;
                } pair;
        } data;
} object;

object *nil;
object *false;
object *true;
object *symbol_table;

object *empty_env;
object *global_env;

#endif

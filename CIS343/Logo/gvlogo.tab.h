/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     EQUAL = 258,
     VAR0 = 259,
     VAR1 = 260,
     VAR2 = 261,
     VAR3 = 262,
     VAR4 = 263,
     GOTO = 264,
     WHERE = 265,
     SEP = 266,
     PENUP = 267,
     PENDOWN = 268,
     PRINT = 269,
     CHANGE_COLOR = 270,
     COLOR = 271,
     CLEAR = 272,
     TURN = 273,
     LOOP = 274,
     MOVE = 275,
     NUMBER = 276,
     END = 277,
     SAVE = 278,
     PLUS = 279,
     SUB = 280,
     MULT = 281,
     DIV = 282,
     STRING = 283,
     QSTRING = 284,
     PATHNAME = 285
   };
#endif
/* Tokens.  */
#define EQUAL 258
#define VAR0 259
#define VAR1 260
#define VAR2 261
#define VAR3 262
#define VAR4 263
#define GOTO 264
#define WHERE 265
#define SEP 266
#define PENUP 267
#define PENDOWN 268
#define PRINT 269
#define CHANGE_COLOR 270
#define COLOR 271
#define CLEAR 272
#define TURN 273
#define LOOP 274
#define MOVE 275
#define NUMBER 276
#define END 277
#define SAVE 278
#define PLUS 279
#define SUB 280
#define MULT 281
#define DIV 282
#define STRING 283
#define QSTRING 284
#define PATHNAME 285




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 67 "gvlogo.y"
{
	float* var;
	float f;
	char* s;
}
/* Line 1529 of yacc.c.  */
#line 115 "gvlogo.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
} YYLTYPE;
# define yyltype YYLTYPE /* obsolescent; will be withdrawn */
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif

extern YYLTYPE yylloc;

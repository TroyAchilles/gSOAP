#define PRAGMA 257
#define AUTO 258
#define DOUBLE 259
#define INT 260
#define STRUCT 261
#define BREAK 262
#define ELSE 263
#define LONG 264
#define SWITCH 265
#define CASE 266
#define ENUM 267
#define REGISTER 268
#define TYPEDEF 269
#define CHAR 270
#define EXTERN 271
#define RETURN 272
#define UNION 273
#define CONST 274
#define FLOAT 275
#define SHORT 276
#define UNSIGNED 277
#define CONTINUE 278
#define FOR 279
#define SIGNED 280
#define VOID 281
#define DEFAULT 282
#define GOTO 283
#define SIZEOF 284
#define VOLATILE 285
#define DO 286
#define IF 287
#define STATIC 288
#define WHILE 289
#define CLASS 290
#define PRIVATE 291
#define PROTECTED 292
#define PUBLIC 293
#define VIRTUAL 294
#define INLINE 295
#define OPERATOR 296
#define LLONG 297
#define BOOL 298
#define CFALSE 299
#define CTRUE 300
#define WCHAR 301
#define TIME 302
#define USING 303
#define NAMESPACE 304
#define ULLONG 305
#define MUSTUNDERSTAND 306
#define SIZE 307
#define FRIEND 308
#define TEMPLATE 309
#define EXPLICIT 310
#define TYPENAME 311
#define MUTABLE 312
#define FINAL 313
#define null 314
#define RESTRICT 315
#define OVERRIDE 316
#define UCHAR 317
#define USHORT 318
#define UINT 319
#define ULONG 320
#define NONE 321
#define ID 322
#define LAB 323
#define TYPE 324
#define LNG 325
#define DBL 326
#define CHR 327
#define TAG 328
#define STR 329
#define PA 330
#define NA 331
#define TA 332
#define DA 333
#define MA 334
#define AA 335
#define XA 336
#define OA 337
#define LA 338
#define RA 339
#define OR 340
#define AN 341
#define EQ 342
#define NE 343
#define LE 344
#define GE 345
#define LS 346
#define RS 347
#define AR 348
#define PP 349
#define NN 350
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union
{
  Symbol  *sym;
  LONG64  i;
  double  r;
  char    c;
  char    *s;
  Tnode   *typ;
  Storage sto;
  Node    rec;
  Entry   *e;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
extern YYSTYPE yylval;

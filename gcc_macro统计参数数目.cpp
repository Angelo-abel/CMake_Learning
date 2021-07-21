100

This is actually compiler dependent, and not supported by any standard.

Here however you have a macro implementation that does the count:

#define PP_NARG(...) \
         PP_NARG_(__VA_ARGS__,PP_RSEQ_N())
#define PP_NARG_(...) \
         PP_ARG_N(__VA_ARGS__)
#define PP_ARG_N( \
          _1, _2, _3, _4, _5, _6, _7, _8, _9,_10, \
         _11,_12,_13,_14,_15,_16,_17,_18,_19,_20, \
         _21,_22,_23,_24,_25,_26,_27,_28,_29,_30, \
         _31,_32,_33,_34,_35,_36,_37,_38,_39,_40, \
         _41,_42,_43,_44,_45,_46,_47,_48,_49,_50, \
         _51,_52,_53,_54,_55,_56,_57,_58,_59,_60, \
         _61,_62,_63,N,...) N
#define PP_RSEQ_N() \
         63,62,61,60,                   \
         59,58,57,56,55,54,53,52,51,50, \
         49,48,47,46,45,44,43,42,41,40, \
         39,38,37,36,35,34,33,32,31,30, \
         29,28,27,26,25,24,23,22,21,20, \
         19,18,17,16,15,14,13,12,11,10, \
         9,8,7,6,5,4,3,2,1,0

/* Some test cases */


PP_NARG(A) -> 1
PP_NARG(A,B) -> 2
PP_NARG(A,B,C) -> 3
PP_NARG(A,B,C,D) -> 4
PP_NARG(A,B,C,D,E) -> 5
PP_NARG(1,2,3,4,5,6,7,8,9,0,
         1,2,3,4,5,6,7,8,9,0,
         1,2,3,4,5,6,7,8,9,0,
         1,2,3,4,5,6,7,8,9,0,
         1,2,3,4,5,6,7,8,9,0,
         1,2,3,4,5,6,7,8,9,0,
         1,2,3) -> 63
 
  
#define PP_THIRD_ARG(a,b,c,...) c
#define VA_OPT_SUPPORTED_I(...) PP_THIRD_ARG(__VA_OPT__(,),true,false,)
#define VA_OPT_SUPPORTED VA_OPT_SUPPORTED_I(?)
If __VA_OPT__ is supported, VA_OPT_SUPPORTED_I(?) expands to PP_THIRD_ARG(,,true,false,), so the third argument is true; otherwise, VA_OPT_SUPPORTED_I(?) expands to PP_THIRD_ARG(__VA_OPT__(,),true,false,), the third argument is false.

Edit: As Edward Diener's answer notes, GCC >= 8 issues a warning or error whenever it sees __VA_OPT__, if -pedantic mode is on and __VA_OPT__ is not enabled (e.g. in -std=c++17). This is GCC bug 98859. One might have to special-case GCC to avoid this diagnostic.

#if __cplusplus <= 201703 && defined __GNUC__ \
  && !defined __clang__ && !defined __EDG__ // These compilers pretend to be GCC
#  define VA_OPT_SUPPORTED false
#endif
1. As chris mentions, if __VA_OPT__(,) expands to ,, there will be 2 empty arguments, otherwise there will be 1 argument. So it's possible to test PP_NARG(__VA_OPT__(,)) == 2, where PP_NARG is a macro to count the number of arguments. To adapt to this test, the definition of PP_NARG can be simplified and inlined.

Share

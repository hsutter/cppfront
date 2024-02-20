
#define CPP2_IMPORT_STD          Yes

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "pure2-regex.cpp2"

#line 134 "pure2-regex.cpp2"
class test_perl_tests;
  

//=== Cpp2 type definitions and function declarations ===========================

#line 1 "pure2-regex.cpp2"
[[nodiscard]] auto create_result(cpp2::in<std::string> resultExpr, auto const& r) -> std::string;

#line 93 "pure2-regex.cpp2"
template<typename M> auto test(M const& regex, cpp2::in<int> id, cpp2::in<std::string> regex_str, cpp2::in<std::string> str, cpp2::in<std::string> kind, cpp2::in<std::string> resultExpr, 
           cpp2::in<std::string> resultExpected) -> void;

#line 134 "pure2-regex.cpp2"
class test_perl_tests {

  private: std::string var_regex_0 {"abc"}; 

  private: std::string var_regex_1 {"abc"}; 

  private: std::string var_regex_2 {"abc"}; 

  private: std::string var_regex_3 {"abc"}; 

  private: std::string var_regex_4 {"abc"}; 

  private: std::string var_regex_5 {"abc"}; 

  private: std::string var_regex_6 {"abc"}; 

  private: std::string var_regex_7 {"abc"}; 

  private: std::string var_regex_8 {"abc"}; 

  private: std::string var_regex_9 {"abc"}; 

  private: std::string var_regex_10 {"abc"}; 

  private: std::string var_regex_11 {"abc"}; 

  private: std::string var_regex_12 {"ab*c"}; 

  private: std::string var_regex_13 {"ab*c"}; 

  private: std::string var_regex_14 {"ab*c"}; 

  private: std::string var_regex_15 {"ab*bc"}; 

  private: std::string var_regex_16 {"ab*bc"}; 

  private: std::string var_regex_17 {"ab*bc"}; 

  private: std::string var_regex_18 {"ab*bc"}; 

  private: std::string var_regex_19 {"ab*bc"}; 

  private: std::string var_regex_20 {"ab*bc"}; 

  private: std::string var_regex_21 {"ab*bc"}; 

  private: std::string var_regex_22 {"ab*bc"}; 

  private: std::string var_regex_23 {"ab*bc"}; 

  private: std::string var_regex_24 {".{1}"}; 

  private: std::string var_regex_25 {".{1}"}; 

  private: std::string var_regex_26 {".{1}"}; 

  private: std::string var_regex_27 {".{3,4}"}; 

  private: std::string var_regex_28 {".{3,4}"}; 

  private: std::string var_regex_29 {".{3,4}"}; 

  private: std::string var_regex_30 {"\\N{1}"}; 

  private: std::string var_regex_31 {"\\N{1}"}; 

  private: std::string var_regex_32 {"\\N{1}"}; 

  private: std::string var_regex_33 {"\\N{3,4}"}; 

  private: std::string var_regex_34 {"\\N{3,4}"}; 

  private: std::string var_regex_35 {"\\N{3,4}"}; 

  private: std::string var_regex_36 {"\\N{ 3 , 4 }"}; 

  private: std::string var_regex_37 {"ab{0,}bc"}; 

  private: std::string var_regex_38 {"ab{0,}bc"}; 

  private: std::string var_regex_39 {"ab{0,}bc"}; 

  private: std::string var_regex_40 {"ab+bc"}; 

  private: std::string var_regex_41 {"ab+bc"}; 

  private: std::string var_regex_42 {"ab+bc"}; 

  private: std::string var_regex_43 {"ab+bc"}; 

  private: std::string var_regex_44 {"ab+bc"}; 

  private: std::string var_regex_45 {"ab{1,}bc"}; 

  private: std::string var_regex_46 {"ab+bc"}; 

  private: std::string var_regex_47 {"ab+bc"}; 

  private: std::string var_regex_48 {"ab+bc"}; 

  private: std::string var_regex_49 {"ab{1,}bc"}; 

  private: std::string var_regex_50 {"ab{1,}bc"}; 

  private: std::string var_regex_51 {"ab{1,}bc"}; 

  private: std::string var_regex_52 {"ab{1,3}bc"}; 

  private: std::string var_regex_53 {"ab{1,3}bc"}; 

  private: std::string var_regex_54 {"ab{1,3}bc"}; 

  private: std::string var_regex_55 {"ab{3,4}bc"}; 

  private: std::string var_regex_56 {"ab{3,4}bc"}; 

  private: std::string var_regex_57 {"ab{3,4}bc"}; 

  private: std::string var_regex_58 {"ab{4,5}bc"}; 

  private: std::string var_regex_59 {"ab?bc"}; 

  private: std::string var_regex_60 {"ab?bc"}; 

  private: std::string var_regex_61 {"ab{0,1}bc"}; 

  private: std::string var_regex_62 {"ab?bc"}; 

  private: std::string var_regex_63 {"ab?c"}; 

  private: std::string var_regex_64 {"ab{0,1}c"}; 

  private: std::string var_regex_65 {"^abc\$"}; 

  private: std::string var_regex_66 {"^abc\$"}; 

  private: std::string var_regex_67 {"^abc"}; 

  private: std::string var_regex_68 {"^abc\$"}; 

  private: std::string var_regex_69 {"abc\$"}; 

  private: std::string var_regex_70 {"abc\$"}; 

  private: std::string var_regex_71 {"^"}; 

  private: std::string var_regex_72 {"\$"}; 

  private: std::string var_regex_73 {"a.c"}; 

  private: std::string var_regex_74 {"a.c"}; 

  private: std::string var_regex_75 {"a\\Nc"}; 

  private: std::string var_regex_76 {"a.*c"}; 

  private: std::string var_regex_77 {"a\\N*c"}; 

  private: std::string var_regex_78 {"a.*c"}; 

  private: std::string var_regex_79 {"a\\N*c"}; 

  private: std::string var_regex_80 {"a[bc]d"}; 

  private: std::string var_regex_81 {"a[bc]d"}; 

  private: std::string var_regex_82 {"a[b]d"}; 

  private: std::string var_regex_83 {"[a][b][d]"}; 

  private: std::string var_regex_84 {".[b]."}; 

  private: std::string var_regex_85 {".[b]."}; 

  private: std::string var_regex_86 {"a[b-d]e"}; 

  private: std::string var_regex_87 {"a[b-d]e"}; 

  private: std::string var_regex_88 {"a[b-d]"}; 

  private: std::string var_regex_89 {"a[-b]"}; 

  private: std::string var_regex_90 {"a[b-]"}; 

  private: std::string var_regex_91 {"a]"}; 

  private: std::string var_regex_92 {"a[]]b"}; 

  private: std::string var_regex_93 {"a[^bc]d"}; 

  private: std::string var_regex_94 {"a[^bc]d"}; 

  private: std::string var_regex_95 {"a[^-b]c"}; 

  private: std::string var_regex_96 {"a[^-b]c"}; 

  private: std::string var_regex_97 {"a[^]b]c"}; 

  private: std::string var_regex_98 {"a[^]b]c"}; 

  private: std::string var_regex_99 {"\ba\b"}; 

  private: std::string var_regex_100 {"\ba\b"}; 

  private: std::string var_regex_101 {"\ba\b"}; 

  private: std::string var_regex_102 {"\by\b"}; 

  private: std::string var_regex_103 {"\by\b"}; 

  private: std::string var_regex_104 {"\by\b"}; 

  private: std::string var_regex_105 {"\Ba\B"}; 

  private: std::string var_regex_106 {"\Ba\B"}; 

  private: std::string var_regex_107 {"\Ba\B"}; 

  private: std::string var_regex_108 {"\By\b"}; 

  private: std::string var_regex_109 {"\By\b"}; 

  private: std::string var_regex_110 {"\By\b"}; 

  private: std::string var_regex_111 {"\By\b"}; 

  private: std::string var_regex_112 {"\by\B"}; 

  private: std::string var_regex_113 {"\By\B"}; 

  private: std::string var_regex_114 {"\b"}; 

  private: std::string var_regex_115 {"\B"}; 

  private: std::string var_regex_116 {"\w"}; 

  private: std::string var_regex_117 {"\w"}; 

  private: std::string var_regex_118 {"\W"}; 

  private: std::string var_regex_119 {"\W"}; 

  private: std::string var_regex_120 {"a\sb"}; 

  private: std::string var_regex_121 {"a\sb"}; 

  private: std::string var_regex_122 {"a\Sb"}; 

  private: std::string var_regex_123 {"a\Sb"}; 

  private: std::string var_regex_124 {"\d"}; 

  private: std::string var_regex_125 {"\d"}; 

  private: std::string var_regex_126 {"\D"}; 

  private: std::string var_regex_127 {"\D"}; 

  private: std::string var_regex_128 {"[\w]"}; 

  private: std::string var_regex_129 {"[\w]"}; 

  private: std::string var_regex_130 {"[\W]"}; 

  private: std::string var_regex_131 {"[\W]"}; 

  private: std::string var_regex_132 {"a[\s]b"}; 

  private: std::string var_regex_133 {"a[\s]b"}; 

  private: std::string var_regex_134 {"a[\S]b"}; 

  private: std::string var_regex_135 {"a[\S]b"}; 

  private: std::string var_regex_136 {"[\d]"}; 

  private: std::string var_regex_137 {"[\d]"}; 

  private: std::string var_regex_138 {"[\D]"}; 

  private: std::string var_regex_139 {"[\D]"}; 

  private: std::string var_regex_140 {"ab|cd"}; 

  private: std::string var_regex_141 {"ab|cd"}; 

  private: std::string var_regex_142 {"()ef"}; 

  private: std::string var_regex_143 {"()ef"}; 

  private: std::string var_regex_144 {"()ef"}; 

  private: std::string var_regex_145 {"()ef"}; 

  private: std::string var_regex_146 {"()ef"}; 

  private: std::string var_regex_147 {"\$b"}; 

  private: std::string var_regex_148 {"a\(b"}; 

  private: std::string var_regex_149 {"a\(*b"}; 

  private: std::string var_regex_150 {"a\(*b"}; 

  private: std::string var_regex_151 {"a\\b"}; 

  private: std::string var_regex_152 {"((a))"}; 

  private: std::string var_regex_153 {"((a))"}; 

  private: std::string var_regex_154 {"((a))"}; 

  private: std::string var_regex_155 {"(foo)(\g-2)"}; 

  private: std::string var_regex_156 {"(foo)(\g-2)(foo)(\g-2)"}; 

  private: std::string var_regex_157 {"(([abc]+) \g-1)(([abc]+) \g{-1})"}; 

  private: std::string var_regex_158 {"(a)(b)(c)\g1\g2\g3"}; 

#line 455 "pure2-regex.cpp2"
  private: std::string var_regex_159 {"abc"}; 

#line 458 "pure2-regex.cpp2"
  private: std::string var_regex_160 {"abc"}; 

#line 461 "pure2-regex.cpp2"
  private: std::string var_regex_161 {"abc"}; 

#line 464 "pure2-regex.cpp2"
  private: std::string var_regex_162 {"abc"}; 

#line 467 "pure2-regex.cpp2"
  private: std::string var_regex_163 {"abc"}; 

#line 470 "pure2-regex.cpp2"
  private: std::string var_regex_164 {"abc"}; 

#line 473 "pure2-regex.cpp2"
  private: std::string var_regex_165 {"ab*c"}; 

#line 476 "pure2-regex.cpp2"
  private: std::string var_regex_166 {"ab*bc"}; 

#line 479 "pure2-regex.cpp2"
  private: std::string var_regex_167 {"ab*bc"}; 

#line 482 "pure2-regex.cpp2"
  private: std::string var_regex_168 {"ab*?bc"}; 

#line 485 "pure2-regex.cpp2"
  private: std::string var_regex_169 {"ab{0,}?bc"}; 

#line 488 "pure2-regex.cpp2"
  private: std::string var_regex_170 {"ab+?bc"}; 

#line 491 "pure2-regex.cpp2"
  private: std::string var_regex_171 {"ab+bc"}; 

#line 494 "pure2-regex.cpp2"
  private: std::string var_regex_172 {"ab+bc"}; 

#line 497 "pure2-regex.cpp2"
  private: std::string var_regex_173 {"ab{1,}bc"}; 

#line 500 "pure2-regex.cpp2"
  private: std::string var_regex_174 {"ab+bc"}; 

#line 503 "pure2-regex.cpp2"
  private: std::string var_regex_175 {"ab{1,}?bc"}; 

#line 506 "pure2-regex.cpp2"
  private: std::string var_regex_176 {"ab{1,3}?bc"}; 

#line 509 "pure2-regex.cpp2"
  private: std::string var_regex_177 {"ab{3,4}?bc"}; 

#line 512 "pure2-regex.cpp2"
  private: std::string var_regex_178 {"ab{4,5}?bc"}; 

#line 515 "pure2-regex.cpp2"
  private: std::string var_regex_179 {"ab??bc"}; 

#line 518 "pure2-regex.cpp2"
  private: std::string var_regex_180 {"ab??bc"}; 

#line 521 "pure2-regex.cpp2"
  private: std::string var_regex_181 {"ab{0,1}?bc"}; 

#line 524 "pure2-regex.cpp2"
  private: std::string var_regex_182 {"ab??bc"}; 

#line 527 "pure2-regex.cpp2"
  private: std::string var_regex_183 {"ab??c"}; 

#line 530 "pure2-regex.cpp2"
  private: std::string var_regex_184 {"ab{0,1}?c"}; 

#line 533 "pure2-regex.cpp2"
  private: std::string var_regex_185 {"^abc\$"}; 

#line 536 "pure2-regex.cpp2"
  private: std::string var_regex_186 {"^abc\$"}; 

#line 539 "pure2-regex.cpp2"
  private: std::string var_regex_187 {"^abc"}; 

#line 542 "pure2-regex.cpp2"
  private: std::string var_regex_188 {"^abc\$"}; 

#line 545 "pure2-regex.cpp2"
  private: std::string var_regex_189 {"abc\$"}; 

#line 548 "pure2-regex.cpp2"
  private: std::string var_regex_190 {"^"}; 

#line 551 "pure2-regex.cpp2"
  private: std::string var_regex_191 {"\$"}; 

#line 554 "pure2-regex.cpp2"
  private: std::string var_regex_192 {"a.c"}; 

#line 557 "pure2-regex.cpp2"
  private: std::string var_regex_193 {"a.c"}; 

#line 560 "pure2-regex.cpp2"
  private: std::string var_regex_194 {"a\\Nc"}; 

#line 563 "pure2-regex.cpp2"
  private: std::string var_regex_195 {"a.*?c"}; 

#line 566 "pure2-regex.cpp2"
  private: std::string var_regex_196 {"a.*c"}; 

#line 569 "pure2-regex.cpp2"
  private: std::string var_regex_197 {"a[bc]d"}; 

#line 572 "pure2-regex.cpp2"
  private: std::string var_regex_198 {"a[bc]d"}; 

#line 575 "pure2-regex.cpp2"
  private: std::string var_regex_199 {"a[b-d]e"}; 

#line 578 "pure2-regex.cpp2"
  private: std::string var_regex_200 {"a[b-d]e"}; 

#line 581 "pure2-regex.cpp2"
  private: std::string var_regex_201 {"a[b-d]"}; 

#line 584 "pure2-regex.cpp2"
  private: std::string var_regex_202 {"a[-b]"}; 

#line 587 "pure2-regex.cpp2"
  private: std::string var_regex_203 {"a[b-]"}; 

#line 590 "pure2-regex.cpp2"
  private: std::string var_regex_204 {"a]"}; 

#line 593 "pure2-regex.cpp2"
  private: std::string var_regex_205 {"a[]]b"}; 

#line 596 "pure2-regex.cpp2"
  private: std::string var_regex_206 {"a[^bc]d"}; 

#line 599 "pure2-regex.cpp2"
  private: std::string var_regex_207 {"a[^bc]d"}; 

#line 602 "pure2-regex.cpp2"
  private: std::string var_regex_208 {"a[^-b]c"}; 

#line 605 "pure2-regex.cpp2"
  private: std::string var_regex_209 {"a[^-b]c"}; 

#line 608 "pure2-regex.cpp2"
  private: std::string var_regex_210 {"a[^]b]c"}; 

#line 611 "pure2-regex.cpp2"
  private: std::string var_regex_211 {"a[^]b]c"}; 

#line 614 "pure2-regex.cpp2"
  private: std::string var_regex_212 {"ab|cd"}; 

#line 617 "pure2-regex.cpp2"
  private: std::string var_regex_213 {"ab|cd"}; 

#line 620 "pure2-regex.cpp2"
  private: std::string var_regex_214 {"()ef"}; 

#line 623 "pure2-regex.cpp2"
  private: std::string var_regex_215 {"\$b"}; 

#line 626 "pure2-regex.cpp2"
  private: std::string var_regex_216 {"a\(b"}; 

#line 629 "pure2-regex.cpp2"
  private: std::string var_regex_217 {"a\(*b"}; 

#line 632 "pure2-regex.cpp2"
  private: std::string var_regex_218 {"a\(*b"}; 

#line 635 "pure2-regex.cpp2"
  private: std::string var_regex_219 {"a\\b"}; 

#line 638 "pure2-regex.cpp2"
  private: std::string var_regex_220 {"((a))"}; 

#line 641 "pure2-regex.cpp2"
  private: std::string var_regex_221 {"(a)b(c)"}; 

#line 644 "pure2-regex.cpp2"
  private: std::string var_regex_222 {"a+b+c"}; 

#line 647 "pure2-regex.cpp2"
  private: std::string var_regex_223 {"a{1,}b{1,}c"}; 

#line 650 "pure2-regex.cpp2"
  private: std::string var_regex_224 {"a.+?c"}; 

#line 653 "pure2-regex.cpp2"
  private: std::string var_regex_225 {"a.*?c"}; 

#line 656 "pure2-regex.cpp2"
  private: std::string var_regex_226 {"a.{0,5}?c"}; 

#line 659 "pure2-regex.cpp2"
  private: std::string var_regex_227 {"(a+|b)*"}; 

#line 662 "pure2-regex.cpp2"
  private: std::string var_regex_228 {"(a+|b){0,}"}; 

#line 665 "pure2-regex.cpp2"
  private: std::string var_regex_229 {"(a+|b)+"}; 

#line 668 "pure2-regex.cpp2"
  private: std::string var_regex_230 {"(a+|b){1,}"}; 

#line 671 "pure2-regex.cpp2"
  private: std::string var_regex_231 {"(a+|b)?"}; 

#line 674 "pure2-regex.cpp2"
  private: std::string var_regex_232 {"(a+|b){0,1}"}; 

#line 677 "pure2-regex.cpp2"
  private: std::string var_regex_233 {"(a+|b){0,1}?"}; 

#line 680 "pure2-regex.cpp2"
  private: std::string var_regex_234 {"[^ab]*"}; 

#line 683 "pure2-regex.cpp2"
  private: std::string var_regex_235 {"abc"}; 

#line 686 "pure2-regex.cpp2"
  private: std::string var_regex_236 {"a*"}; 

#line 689 "pure2-regex.cpp2"
  private: std::string var_regex_237 {"([abc])*d"}; 

#line 692 "pure2-regex.cpp2"
  private: std::string var_regex_238 {"([abc])*bcd"}; 

#line 695 "pure2-regex.cpp2"
  private: std::string var_regex_239 {"a|b|c|d|e"}; 

#line 698 "pure2-regex.cpp2"
  private: std::string var_regex_240 {"(a|b|c|d|e)f"}; 

#line 701 "pure2-regex.cpp2"
  private: std::string var_regex_241 {"abcd*efg"}; 

#line 704 "pure2-regex.cpp2"
  private: std::string var_regex_242 {"ab*"}; 

#line 707 "pure2-regex.cpp2"
  private: std::string var_regex_243 {"ab*"}; 

#line 710 "pure2-regex.cpp2"
  private: std::string var_regex_244 {"(ab|cd)e"}; 

#line 713 "pure2-regex.cpp2"
  private: std::string var_regex_245 {"[abhgefdc]ij"}; 

#line 716 "pure2-regex.cpp2"
  private: std::string var_regex_246 {"^(ab|cd)e"}; 

#line 719 "pure2-regex.cpp2"
  private: std::string var_regex_247 {"(abc|)ef"}; 

#line 722 "pure2-regex.cpp2"
  private: std::string var_regex_248 {"(a|b)c*d"}; 

#line 725 "pure2-regex.cpp2"
  private: std::string var_regex_249 {"(ab|ab*)bc"}; 

#line 728 "pure2-regex.cpp2"
  private: std::string var_regex_250 {"a([bc]*)c*"}; 

#line 731 "pure2-regex.cpp2"
  private: std::string var_regex_251 {"a([bc]*)(c*d)"}; 

#line 734 "pure2-regex.cpp2"
  private: std::string var_regex_252 {"a([bc]+)(c*d)"}; 

#line 737 "pure2-regex.cpp2"
  private: std::string var_regex_253 {"a([bc]*)(c+d)"}; 

#line 740 "pure2-regex.cpp2"
  private: std::string var_regex_254 {"a[bcd]*dcdcde"}; 

#line 743 "pure2-regex.cpp2"
  private: std::string var_regex_255 {"a[bcd]+dcdcde"}; 

#line 746 "pure2-regex.cpp2"
  private: std::string var_regex_256 {"(ab|a)b*c"}; 

#line 749 "pure2-regex.cpp2"
  private: std::string var_regex_257 {"((a)(b)c)(d)"}; 

#line 752 "pure2-regex.cpp2"
  private: std::string var_regex_258 {"[a-zA-Z_][a-zA-Z0-9_]*"}; 

#line 755 "pure2-regex.cpp2"
  private: std::string var_regex_259 {"^a(bc+|b[eh])g|.h\$"}; 

#line 758 "pure2-regex.cpp2"
  private: std::string var_regex_260 {"(bc+d\$|ef*g.|h?i(j|k))"}; 

#line 761 "pure2-regex.cpp2"
  private: std::string var_regex_261 {"(bc+d\$|ef*g.|h?i(j|k))"}; 

#line 764 "pure2-regex.cpp2"
  private: std::string var_regex_262 {"(bc+d\$|ef*g.|h?i(j|k))"}; 

#line 767 "pure2-regex.cpp2"
  private: std::string var_regex_263 {"(bc+d\$|ef*g.|h?i(j|k))"}; 

#line 770 "pure2-regex.cpp2"
  private: std::string var_regex_264 {"(bc+d\$|ef*g.|h?i(j|k))"}; 

#line 773 "pure2-regex.cpp2"
  private: std::string var_regex_265 {"((((((((((a))))))))))"}; 

#line 776 "pure2-regex.cpp2"
  private: std::string var_regex_266 {"((((((((((a))))))))))\10"}; 

#line 779 "pure2-regex.cpp2"
  private: std::string var_regex_267 {"(((((((((a)))))))))"}; 

#line 782 "pure2-regex.cpp2"
  private: std::string var_regex_268 {"multiple words of text"}; 

#line 785 "pure2-regex.cpp2"
  private: std::string var_regex_269 {"multiple words"}; 

#line 788 "pure2-regex.cpp2"
  private: std::string var_regex_270 {"(.*)c(.*)"}; 

#line 791 "pure2-regex.cpp2"
  private: std::string var_regex_271 {"\((.*), (.*)\)"}; 

#line 794 "pure2-regex.cpp2"
  private: std::string var_regex_272 {"[k]"}; 

#line 797 "pure2-regex.cpp2"
  private: std::string var_regex_273 {"abcd"}; 

#line 800 "pure2-regex.cpp2"
  private: std::string var_regex_274 {"a(bc)d"}; 

#line 803 "pure2-regex.cpp2"
  private: std::string var_regex_275 {"a[-]?c"}; 

#line 806 "pure2-regex.cpp2"
  private: std::string var_regex_276 {"(abc)\1"}; 

#line 809 "pure2-regex.cpp2"
  private: std::string var_regex_277 {"([a-c]*)\1"}; 

  private: std::string var_regex_278 {"a++a"}; 

  private: std::string var_regex_279 {"a*+a"}; 

  private: std::string var_regex_280 {"a{1,5}+a"}; 

  private: std::string var_regex_281 {"a?+a"}; 

  private: std::string var_regex_282 {"a++b"}; 

  private: std::string var_regex_283 {"a*+b"}; 

  private: std::string var_regex_284 {"a{1,5}+b"}; 

  private: std::string var_regex_285 {"a?+b"}; 

  private: std::string var_regex_286 {"fooa++a"}; 

  private: std::string var_regex_287 {"fooa*+a"}; 

  private: std::string var_regex_288 {"fooa{1,5}+a"}; 

  private: std::string var_regex_289 {"fooa?+a"}; 

  private: std::string var_regex_290 {"fooa++b"}; 

  private: std::string var_regex_291 {"fooa*+b"}; 

  private: std::string var_regex_292 {"fooa{1,5}+b"}; 

  private: std::string var_regex_293 {"fooa?+b"}; 

  private: std::string var_regex_294 {"(aA)++(aA)"}; 

  private: std::string var_regex_295 {"(aA|bB)++(aA|bB)"}; 

  private: std::string var_regex_296 {"(aA)*+(aA)"}; 

  private: std::string var_regex_297 {"(aA|bB)*+(aA|bB)"}; 

  private: std::string var_regex_298 {"(aA){1,5}+(aA)"}; 

  private: std::string var_regex_299 {"(aA|bB){1,5}+(aA|bB)"}; 

  private: std::string var_regex_300 {"(aA)?+(aA)"}; 

  private: std::string var_regex_301 {"(aA|bB)?+(aA|bB)"}; 

  private: std::string var_regex_302 {"(aA)++b"}; 

  private: std::string var_regex_303 {"(aA|bB)++b"}; 

  private: std::string var_regex_304 {"(aA)*+b"}; 

  private: std::string var_regex_305 {"(aA|bB)*+b"}; 

  private: std::string var_regex_306 {"(aA){1,5}+b"}; 

  private: std::string var_regex_307 {"(aA|bB){1,5}+b"}; 

  private: std::string var_regex_308 {"(aA)?+b"}; 

  private: std::string var_regex_309 {"(aA|bB)?+b"}; 

  private: std::string var_regex_310 {"foo(aA)++(aA)"}; 

  private: std::string var_regex_311 {"foo(aA|bB)++(aA|bB)"}; 

  private: std::string var_regex_312 {"foo(aA)*+(aA)"}; 

  private: std::string var_regex_313 {"foo(aA|bB)*+(aA|bB)"}; 

  private: std::string var_regex_314 {"foo(aA){1,5}+(aA)"}; 

  private: std::string var_regex_315 {"foo(aA|bB){1,5}+(aA|bB)"}; 

  private: std::string var_regex_316 {"foo(aA)?+(aA)"}; 

  private: std::string var_regex_317 {"foo(aA|bB)?+(aA|bB)"}; 

  private: std::string var_regex_318 {"foo(aA)++b"}; 

  private: std::string var_regex_319 {"foo(aA|bB)++b"}; 

  private: std::string var_regex_320 {"foo(aA)*+b"}; 

  private: std::string var_regex_321 {"foo(aA|bB)*+b"}; 

  private: std::string var_regex_322 {"foo(aA){1,5}+b"}; 

  private: std::string var_regex_323 {"foo(aA|bB){1,5}+b"}; 

  private: std::string var_regex_324 {"foo(aA)?+b"}; 

  private: std::string var_regex_325 {"foo(aA|bB)?+b"}; 

  private: std::string var_regex_326 {"foo(\h+)bar"}; 

  private: std::string var_regex_327 {"(\H+)(\h)"}; 

  private: std::string var_regex_328 {"(\h+)(\H)"}; 

  private: std::string var_regex_329 {"foo(\h)bar"}; 

  private: std::string var_regex_330 {"(\H)(\h)"}; 

  private: std::string var_regex_331 {"(\h)(\H)"}; 

  private: std::string var_regex_332 {"foo(\v+)bar"}; 

  private: std::string var_regex_333 {"(\V+)(\v)"}; 

  private: std::string var_regex_334 {"(\v+)(\V)"}; 

  private: std::string var_regex_335 {"foo(\v)bar"}; 

  private: std::string var_regex_336 {"(\V)(\v)"}; 

  private: std::string var_regex_337 {"(\v)(\V)"}; 

  private: std::string var_regex_338 {"foo\Kbar"}; 

  private: std::string var_regex_339 {"foo\t\n\r\f\a\ebar"}; 
  public: auto run() const& -> void;
  private: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_0 {}; private: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_1 {}; private: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_10 {}; private: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::word_boundary_matcher_logic<char,false>,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::word_boundary_matcher_logic<char,false>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_100 {}; private: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::word_boundary_matcher_logic<char,false>,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::word_boundary_matcher_logic<char,false>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_101 {}; private: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::word_boundary_matcher_logic<char,false>,::cpp2::regex::char_matcher_logic<char,'y','y','Y'>,::cpp2::regex::word_boundary_matcher_logic<char,false>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_102 {}; private: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::word_boundary_matcher_logic<char,false>,::cpp2::regex::char_matcher_logic<char,'y','y','Y'>,::cpp2::regex::word_boundary_matcher_logic<char,false>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_103 {}; private: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::word_boundary_matcher_logic<char,false>,::cpp2::regex::char_matcher_logic<char,'y','y','Y'>,::cpp2::regex::word_boundary_matcher_logic<char,false>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_104 {}; private: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::word_boundary_matcher_logic<char,true>,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::word_boundary_matcher_logic<char,true>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_105 {}; private: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::word_boundary_matcher_logic<char,true>,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::word_boundary_matcher_logic<char,true>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_106 {}; private: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::word_boundary_matcher_logic<char,true>,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::word_boundary_matcher_logic<char,true>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_107 {}; private: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::word_boundary_matcher_logic<char,true>,::cpp2::regex::char_matcher_logic<char,'y','y','Y'>,::cpp2::regex::word_boundary_matcher_logic<char,false>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_108 {}; private: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::word_boundary_matcher_logic<char,true>,::cpp2::regex::char_matcher_logic<char,'y','y','Y'>,::cpp2::regex::word_boundary_matcher_logic<char,false>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_109 {}; private: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_11 {}; private: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::word_boundary_matcher_logic<char,true>,::cpp2::regex::char_matcher_logic<char,'y','y','Y'>,::cpp2::regex::word_boundary_matcher_logic<char,false>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_110 {}; private: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::word_boundary_matcher_logic<char,true>,::cpp2::regex::char_matcher_logic<char,'y','y','Y'>,::cpp2::regex::word_boundary_matcher_logic<char,false>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_111 {}; private: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::word_boundary_matcher_logic<char,false>,::cpp2::regex::char_matcher_logic<char,'y','y','Y'>,::cpp2::regex::word_boundary_matcher_logic<char,true>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_112 {}; private: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::word_boundary_matcher_logic<char,true>,::cpp2::regex::char_matcher_logic<char,'y','y','Y'>,::cpp2::regex::word_boundary_matcher_logic<char,true>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_113 {}; private: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::word_boundary_matcher_logic<char,false>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_114 {}; private: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::word_boundary_matcher_logic<char,true>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_115 {}; private: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::named_class_word<char>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_116 {}; private: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::named_class_word<char>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_117 {}; private: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::named_class_not_word<char>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_118 {}; private: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::named_class_not_word<char>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_119 {}; private: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,0,-1,true,false,'*'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_12 {}; private: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::named_class_space<char>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_120 {}; private: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::named_class_space<char>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_121 {}; private: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::named_class_not_space<char>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_122 {}; private: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::named_class_not_space<char>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_123 {}; private: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::named_class_digits<char>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_124 {}; private: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::named_class_digits<char>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_125 {}; private: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::named_class_not_digits<char>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_126 {}; private: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::named_class_not_digits<char>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_127 {}; private: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::class_matcher_logic<char,false,::cpp2::regex::short_word_class<char>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_128 {}; private: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::class_matcher_logic<char,false,::cpp2::regex::short_word_class<char>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_129 {}; private: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,0,-1,true,false,'*'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_13 {}; private: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::class_matcher_logic<char,false,::cpp2::regex::short_not_word_class<char>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_130 {}; private: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::class_matcher_logic<char,false,::cpp2::regex::short_not_word_class<char>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_131 {}; private: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::class_matcher_logic<char,false,::cpp2::regex::short_space_class<char>>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_132 {}; private: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::class_matcher_logic<char,false,::cpp2::regex::short_space_class<char>>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_133 {}; private: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::class_matcher_logic<char,false,::cpp2::regex::short_not_space_class<char>>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_134 {}; private: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::class_matcher_logic<char,false,::cpp2::regex::short_not_space_class<char>>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_135 {}; private: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::class_matcher_logic<char,false,::cpp2::regex::short_digits_class<char>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_136 {}; private: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::class_matcher_logic<char,false,::cpp2::regex::short_digits_class<char>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_137 {}; private: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::class_matcher_logic<char,false,::cpp2::regex::short_not_digits_class<char>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_138 {}; private: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::class_matcher_logic<char,false,::cpp2::regex::short_not_digits_class<char>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_139 {}; private: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,0,-1,true,false,'*'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_14 {}; private: ::cpp2::regex::regular_expression<char,0,1,1,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::alternative_matcher_logic<char,0,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'c','c','C'>,::cpp2::regex::char_matcher_logic<char,'d','d','D'>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_140 {}; private: ::cpp2::regex::regular_expression<char,0,1,1,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::alternative_matcher_logic<char,0,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'c','c','C'>,::cpp2::regex::char_matcher_logic<char,'d','d','D'>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_141 {}; private: ::cpp2::regex::regular_expression<char,0,2,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,"">,::cpp2::regex::matcher_list<char>,::cpp2::regex::group_matcher_end_logic<char,1>>,::cpp2::regex::char_matcher_logic<char,'e','e','E'>,::cpp2::regex::char_matcher_logic<char,'f','f','F'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_142 {}; private: ::cpp2::regex::regular_expression<char,0,2,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,"">,::cpp2::regex::matcher_list<char>,::cpp2::regex::group_matcher_end_logic<char,1>>,::cpp2::regex::char_matcher_logic<char,'e','e','E'>,::cpp2::regex::char_matcher_logic<char,'f','f','F'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_143 {}; private: ::cpp2::regex::regular_expression<char,0,2,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,"">,::cpp2::regex::matcher_list<char>,::cpp2::regex::group_matcher_end_logic<char,1>>,::cpp2::regex::char_matcher_logic<char,'e','e','E'>,::cpp2::regex::char_matcher_logic<char,'f','f','F'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_144 {}; private: ::cpp2::regex::regular_expression<char,0,2,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,"">,::cpp2::regex::matcher_list<char>,::cpp2::regex::group_matcher_end_logic<char,1>>,::cpp2::regex::char_matcher_logic<char,'e','e','E'>,::cpp2::regex::char_matcher_logic<char,'f','f','F'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_145 {}; private: ::cpp2::regex::regular_expression<char,0,2,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,"">,::cpp2::regex::matcher_list<char>,::cpp2::regex::group_matcher_end_logic<char,1>>,::cpp2::regex::char_matcher_logic<char,'e','e','E'>,::cpp2::regex::char_matcher_logic<char,'f','f','F'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_146 {}; private: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::line_end_matcher_logic<char,true,false>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_147 {}; private: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::escaped_char_matcher_logic<char,'(','(','('>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_148 {}; private: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::escaped_char_matcher_logic<char,'(','(','('>,0,-1,true,false,'*'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_149 {}; private: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,0,-1,true,false,'*'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_15 {}; private: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::escaped_char_matcher_logic<char,'(','(','('>,0,-1,true,false,'*'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_150 {}; private: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::escaped_char_matcher_logic<char,'\\','\\','\\'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_151 {}; private: ::cpp2::regex::regular_expression<char,0,3,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,2,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>>,::cpp2::regex::group_matcher_end_logic<char,2>>>,::cpp2::regex::group_matcher_end_logic<char,1>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_152 {}; private: ::cpp2::regex::regular_expression<char,0,3,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,2,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>>,::cpp2::regex::group_matcher_end_logic<char,2>>>,::cpp2::regex::group_matcher_end_logic<char,1>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_153 {}; private: ::cpp2::regex::regular_expression<char,0,3,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,2,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>>,::cpp2::regex::group_matcher_end_logic<char,2>>>,::cpp2::regex::group_matcher_end_logic<char,1>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_154 {}; private: ::cpp2::regex::regular_expression<char,0,3,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'f','f','F'>,::cpp2::regex::char_matcher_logic<char,'o','o','O'>,::cpp2::regex::char_matcher_logic<char,'o','o','O'>>,::cpp2::regex::group_matcher_end_logic<char,1>>,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,2,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::group_ref_matcher_logic<char,1,"\\g-2">>,::cpp2::regex::group_matcher_end_logic<char,2>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_155 {}; private: ::cpp2::regex::regular_expression<char,0,5,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'f','f','F'>,::cpp2::regex::char_matcher_logic<char,'o','o','O'>,::cpp2::regex::char_matcher_logic<char,'o','o','O'>>,::cpp2::regex::group_matcher_end_logic<char,1>>,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,2,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::group_ref_matcher_logic<char,1,"\\g-2">>,::cpp2::regex::group_matcher_end_logic<char,2>>,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,3,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'f','f','F'>,::cpp2::regex::char_matcher_logic<char,'o','o','O'>,::cpp2::regex::char_matcher_logic<char,'o','o','O'>>,::cpp2::regex::group_matcher_end_logic<char,3>>,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,4,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::group_ref_matcher_logic<char,3,"\\g-2">>,::cpp2::regex::group_matcher_end_logic<char,4>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_156 {}; private: ::cpp2::regex::regular_expression<char,0,5,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,2,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::class_matcher_logic<char,false,::cpp2::regex::single_class_entry<char,'a'>,::cpp2::regex::single_class_entry<char,'b'>,::cpp2::regex::single_class_entry<char,'c'>>,1,-1,true,false,'+'>>,::cpp2::regex::group_matcher_end_logic<char,2>>,::cpp2::regex::char_matcher_logic<char,' ',' ',' '>,::cpp2::regex::group_ref_matcher_logic<char,2,"\\g-1">>,::cpp2::regex::group_matcher_end_logic<char,1>>,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,3,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,4,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::class_matcher_logic<char,false,::cpp2::regex::single_class_entry<char,'a'>,::cpp2::regex::single_class_entry<char,'b'>,::cpp2::regex::single_class_entry<char,'c'>>,1,-1,true,false,'+'>>,::cpp2::regex::group_matcher_end_logic<char,4>>,::cpp2::regex::char_matcher_logic<char,' ',' ',' '>,::cpp2::regex::group_ref_matcher_logic<char,4,"\\g{-1}">>,::cpp2::regex::group_matcher_end_logic<char,3>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_157 {}; private: ::cpp2::regex::regular_expression<char,0,4,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>>,::cpp2::regex::group_matcher_end_logic<char,1>>,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,2,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>>,::cpp2::regex::group_matcher_end_logic<char,2>>,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,3,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,3>>,::cpp2::regex::group_ref_matcher_logic<char,1,"\\g1">,::cpp2::regex::group_ref_matcher_logic<char,2,"\\g2">,::cpp2::regex::group_ref_matcher_logic<char,3,"\\g3">>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_158 {}; private: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_159 {}; private: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,0,-1,true,false,'*'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_16 {}; private: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_160 {}; private: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_161 {}; private: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_162 {}; private: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_163 {}; private: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_164 {}; private: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,0,-1,true,false,'*'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_165 {}; private: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,0,-1,true,false,'*'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_166 {}; private: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,0,-1,true,false,'*'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_167 {}; private: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,0,-1,false,false,'*'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_168 {}; private: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,0,-1,true,false>,0,1,true,false,'?'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_169 {}; private: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,0,-1,true,false,'*'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_17 {}; private: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,1,-1,false,false,'+'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_170 {}; private: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,1,-1,true,false,'+'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_171 {}; private: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,1,-1,true,false,'+'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_172 {}; private: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,1,-1,true,false>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_173 {}; private: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,1,-1,true,false,'+'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_174 {}; private: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,1,-1,true,false>,0,1,true,false,'?'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_175 {}; private: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,1,3,true,false>,0,1,true,false,'?'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_176 {}; private: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,3,4,true,false>,0,1,true,false,'?'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_177 {}; private: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,4,5,true,false>,0,1,true,false,'?'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_178 {}; private: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,0,1,false,false,'?'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_179 {}; private: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,0,-1,true,false,'*'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_18 {}; private: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,0,1,false,false,'?'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_180 {}; private: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,0,1,true,false>,0,1,true,false,'?'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_181 {}; private: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,0,1,false,false,'?'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_182 {}; private: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,0,1,false,false,'?'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_183 {}; private: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,0,1,true,false>,0,1,true,false,'?'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_184 {}; private: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::line_start_matcher_logic<char,true>,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>,::cpp2::regex::line_end_matcher_logic<char,true,false>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_185 {}; private: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::line_start_matcher_logic<char,true>,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>,::cpp2::regex::line_end_matcher_logic<char,true,false>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_186 {}; private: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::line_start_matcher_logic<char,true>,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_187 {}; private: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::line_start_matcher_logic<char,true>,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>,::cpp2::regex::line_end_matcher_logic<char,true,false>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_188 {}; private: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>,::cpp2::regex::line_end_matcher_logic<char,true,false>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_189 {}; private: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,0,-1,true,false,'*'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_19 {}; private: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::line_start_matcher_logic<char,true>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_190 {}; private: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::line_end_matcher_logic<char,true,false>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_191 {}; private: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::any_matcher_logic<char>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_192 {}; private: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::any_matcher_logic<char>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_193 {}; private: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::named_class_no_new_line<char>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_194 {}; private: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::any_matcher_logic<char>,0,-1,false,false,'*'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_195 {}; private: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::any_matcher_logic<char>,0,-1,true,false,'*'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_196 {}; private: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::class_matcher_logic<char,false,::cpp2::regex::single_class_entry<char,'b'>,::cpp2::regex::single_class_entry<char,'c'>>,::cpp2::regex::char_matcher_logic<char,'d','d','D'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_197 {}; private: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::class_matcher_logic<char,false,::cpp2::regex::single_class_entry<char,'b'>,::cpp2::regex::single_class_entry<char,'c'>>,::cpp2::regex::char_matcher_logic<char,'d','d','D'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_198 {}; private: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::class_matcher_logic<char,false,::cpp2::regex::range_class_entry<char,'b','d'>>,::cpp2::regex::char_matcher_logic<char,'e','e','E'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_199 {}; private: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_2 {}; private: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,0,-1,true,false,'*'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_20 {}; private: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::class_matcher_logic<char,false,::cpp2::regex::range_class_entry<char,'b','d'>>,::cpp2::regex::char_matcher_logic<char,'e','e','E'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_200 {}; private: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::class_matcher_logic<char,false,::cpp2::regex::range_class_entry<char,'b','d'>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_201 {}; private: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::class_matcher_logic<char,false,::cpp2::regex::single_class_entry<char,'-'>,::cpp2::regex::single_class_entry<char,'b'>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_202 {}; private: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::class_matcher_logic<char,false,::cpp2::regex::single_class_entry<char,'b'>,::cpp2::regex::single_class_entry<char,'-'>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_203 {}; private: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,']',']',']'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_204 {}; private: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::class_matcher_logic<char,false,::cpp2::regex::single_class_entry<char,']'>>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_205 {}; private: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::class_matcher_logic<char,true,::cpp2::regex::single_class_entry<char,'b'>,::cpp2::regex::single_class_entry<char,'c'>>,::cpp2::regex::char_matcher_logic<char,'d','d','D'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_206 {}; private: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::class_matcher_logic<char,true,::cpp2::regex::single_class_entry<char,'b'>,::cpp2::regex::single_class_entry<char,'c'>>,::cpp2::regex::char_matcher_logic<char,'d','d','D'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_207 {}; private: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::class_matcher_logic<char,true,::cpp2::regex::single_class_entry<char,'-'>,::cpp2::regex::single_class_entry<char,'b'>>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_208 {}; private: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::class_matcher_logic<char,true,::cpp2::regex::single_class_entry<char,'-'>,::cpp2::regex::single_class_entry<char,'b'>>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_209 {}; private: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,0,-1,true,false,'*'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_21 {}; private: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::class_matcher_logic<char,true,::cpp2::regex::single_class_entry<char,']'>,::cpp2::regex::single_class_entry<char,'b'>>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_210 {}; private: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::class_matcher_logic<char,true,::cpp2::regex::single_class_entry<char,']'>,::cpp2::regex::single_class_entry<char,'b'>>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_211 {}; private: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,1,1,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::alternative_matcher_logic<char,0,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'c','c','C'>,::cpp2::regex::char_matcher_logic<char,'d','d','D'>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_212 {}; private: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,1,1,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::alternative_matcher_logic<char,0,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'c','c','C'>,::cpp2::regex::char_matcher_logic<char,'d','d','D'>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_213 {}; private: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,2,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,"">,::cpp2::regex::matcher_list<char>,::cpp2::regex::group_matcher_end_logic<char,1>>,::cpp2::regex::char_matcher_logic<char,'e','e','E'>,::cpp2::regex::char_matcher_logic<char,'f','f','F'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_214 {}; private: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::line_end_matcher_logic<char,true,false>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_215 {}; private: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::escaped_char_matcher_logic<char,'(','(','('>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_216 {}; private: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::escaped_char_matcher_logic<char,'(','(','('>,0,-1,true,false,'*'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_217 {}; private: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::escaped_char_matcher_logic<char,'(','(','('>,0,-1,true,false,'*'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_218 {}; private: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::escaped_char_matcher_logic<char,'\\','\\','\\'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_219 {}; private: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,0,-1,true,false,'*'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_22 {}; private: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,3,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,2,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>>,::cpp2::regex::group_matcher_end_logic<char,2>>>,::cpp2::regex::group_matcher_end_logic<char,1>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_220 {}; private: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,3,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>>,::cpp2::regex::group_matcher_end_logic<char,1>>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,2,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,2>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_221 {}; private: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,1,-1,true,false,'+'>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,1,-1,true,false,'+'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_222 {}; private: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,1,-1,true,false>,::cpp2::regex::range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,1,-1,true,false>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_223 {}; private: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::any_matcher_logic<char>,1,-1,false,false,'+'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_224 {}; private: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::any_matcher_logic<char>,0,-1,false,false,'*'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_225 {}; private: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::range_matcher_logic<char,::cpp2::regex::any_matcher_logic<char>,0,5,true,false>,0,1,true,false,'?'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_226 {}; private: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,2,1,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,"">,::cpp2::regex::alternative_matcher_logic<char,0,::cpp2::regex::matcher_list<char,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,1,-1,true,false,'+'>>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>>>,::cpp2::regex::group_matcher_end_logic<char,1>>,0,-1,true,false,'*'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_227 {}; private: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,2,1,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::range_matcher_logic<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,"">,::cpp2::regex::alternative_matcher_logic<char,0,::cpp2::regex::matcher_list<char,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,1,-1,true,false,'+'>>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>>>,::cpp2::regex::group_matcher_end_logic<char,1>>,0,-1,true,false>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_228 {}; private: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,2,1,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,"">,::cpp2::regex::alternative_matcher_logic<char,0,::cpp2::regex::matcher_list<char,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,1,-1,true,false,'+'>>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>>>,::cpp2::regex::group_matcher_end_logic<char,1>>,1,-1,true,false,'+'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_229 {}; private: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,0,-1,true,false,'*'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_23 {}; private: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,2,1,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::range_matcher_logic<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,"">,::cpp2::regex::alternative_matcher_logic<char,0,::cpp2::regex::matcher_list<char,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,1,-1,true,false,'+'>>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>>>,::cpp2::regex::group_matcher_end_logic<char,1>>,1,-1,true,false>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_230 {}; private: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,2,1,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,"">,::cpp2::regex::alternative_matcher_logic<char,0,::cpp2::regex::matcher_list<char,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,1,-1,true,false,'+'>>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>>>,::cpp2::regex::group_matcher_end_logic<char,1>>,0,1,true,false,'?'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_231 {}; private: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,2,1,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::range_matcher_logic<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,"">,::cpp2::regex::alternative_matcher_logic<char,0,::cpp2::regex::matcher_list<char,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,1,-1,true,false,'+'>>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>>>,::cpp2::regex::group_matcher_end_logic<char,1>>,0,1,true,false>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_232 {}; private: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,2,1,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::range_matcher_logic<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,"">,::cpp2::regex::alternative_matcher_logic<char,0,::cpp2::regex::matcher_list<char,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,1,-1,true,false,'+'>>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>>>,::cpp2::regex::group_matcher_end_logic<char,1>>,0,1,true,false>,0,1,true,false,'?'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_233 {}; private: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::class_matcher_logic<char,true,::cpp2::regex::single_class_entry<char,'a'>,::cpp2::regex::single_class_entry<char,'b'>>,0,-1,true,false,'*'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_234 {}; private: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_235 {}; private: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,0,-1,true,false,'*'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_236 {}; private: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,2,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::class_matcher_logic<char,false,::cpp2::regex::single_class_entry<char,'a'>,::cpp2::regex::single_class_entry<char,'b'>,::cpp2::regex::single_class_entry<char,'c'>>>,::cpp2::regex::group_matcher_end_logic<char,1>>,0,-1,true,false,'*'>,::cpp2::regex::char_matcher_logic<char,'d','d','D'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_237 {}; private: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,2,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::class_matcher_logic<char,false,::cpp2::regex::single_class_entry<char,'a'>,::cpp2::regex::single_class_entry<char,'b'>,::cpp2::regex::single_class_entry<char,'c'>>>,::cpp2::regex::group_matcher_end_logic<char,1>>,0,-1,true,false,'*'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>,::cpp2::regex::char_matcher_logic<char,'d','d','D'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_238 {}; private: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,1,1,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::alternative_matcher_logic<char,0,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'d','d','D'>>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'e','e','E'>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_239 {}; private: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::range_matcher_logic<char,::cpp2::regex::any_matcher_logic<char>,1,1,true,false>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_24 {}; private: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,2,1,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,"">,::cpp2::regex::alternative_matcher_logic<char,0,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'d','d','D'>>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'e','e','E'>>>,::cpp2::regex::group_matcher_end_logic<char,1>>,::cpp2::regex::char_matcher_logic<char,'f','f','F'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_240 {}; private: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'d','d','D'>,0,-1,true,false,'*'>,::cpp2::regex::char_matcher_logic<char,'e','e','E'>,::cpp2::regex::char_matcher_logic<char,'f','f','F'>,::cpp2::regex::char_matcher_logic<char,'g','g','G'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_241 {}; private: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,0,-1,true,false,'*'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_242 {}; private: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,0,-1,true,false,'*'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_243 {}; private: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,2,1,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,"">,::cpp2::regex::alternative_matcher_logic<char,0,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'c','c','C'>,::cpp2::regex::char_matcher_logic<char,'d','d','D'>>>,::cpp2::regex::group_matcher_end_logic<char,1>>,::cpp2::regex::char_matcher_logic<char,'e','e','E'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_244 {}; private: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::class_matcher_logic<char,false,::cpp2::regex::single_class_entry<char,'a'>,::cpp2::regex::single_class_entry<char,'b'>,::cpp2::regex::single_class_entry<char,'h'>,::cpp2::regex::single_class_entry<char,'g'>,::cpp2::regex::single_class_entry<char,'e'>,::cpp2::regex::single_class_entry<char,'f'>,::cpp2::regex::single_class_entry<char,'d'>,::cpp2::regex::single_class_entry<char,'c'>>,::cpp2::regex::char_matcher_logic<char,'i','i','I'>,::cpp2::regex::char_matcher_logic<char,'j','j','J'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_245 {}; private: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,2,1,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::line_start_matcher_logic<char,true>,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,"">,::cpp2::regex::alternative_matcher_logic<char,0,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'c','c','C'>,::cpp2::regex::char_matcher_logic<char,'d','d','D'>>>,::cpp2::regex::group_matcher_end_logic<char,1>>,::cpp2::regex::char_matcher_logic<char,'e','e','E'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_246 {}; private: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,2,1,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,"">,::cpp2::regex::alternative_matcher_logic<char,0,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::matcher_list<char,::cpp2::regex::empty_matcher_logic<char>>>,::cpp2::regex::group_matcher_end_logic<char,1>>,::cpp2::regex::char_matcher_logic<char,'e','e','E'>,::cpp2::regex::char_matcher_logic<char,'f','f','F'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_247 {}; private: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,2,1,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,"">,::cpp2::regex::alternative_matcher_logic<char,0,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>>>,::cpp2::regex::group_matcher_end_logic<char,1>>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'c','c','C'>,0,-1,true,false,'*'>,::cpp2::regex::char_matcher_logic<char,'d','d','D'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_248 {}; private: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,2,1,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,"">,::cpp2::regex::alternative_matcher_logic<char,0,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,0,-1,true,false,'*'>>>,::cpp2::regex::group_matcher_end_logic<char,1>>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_249 {}; private: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::range_matcher_logic<char,::cpp2::regex::any_matcher_logic<char>,1,1,true,false>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_25 {}; private: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,2,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::class_matcher_logic<char,false,::cpp2::regex::single_class_entry<char,'b'>,::cpp2::regex::single_class_entry<char,'c'>>,0,-1,true,false,'*'>>,::cpp2::regex::group_matcher_end_logic<char,1>>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'c','c','C'>,0,-1,true,false,'*'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_250 {}; private: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,3,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::class_matcher_logic<char,false,::cpp2::regex::single_class_entry<char,'b'>,::cpp2::regex::single_class_entry<char,'c'>>,0,-1,true,false,'*'>>,::cpp2::regex::group_matcher_end_logic<char,1>>,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,2,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'c','c','C'>,0,-1,true,false,'*'>,::cpp2::regex::char_matcher_logic<char,'d','d','D'>>,::cpp2::regex::group_matcher_end_logic<char,2>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_251 {}; private: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,3,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::class_matcher_logic<char,false,::cpp2::regex::single_class_entry<char,'b'>,::cpp2::regex::single_class_entry<char,'c'>>,1,-1,true,false,'+'>>,::cpp2::regex::group_matcher_end_logic<char,1>>,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,2,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'c','c','C'>,0,-1,true,false,'*'>,::cpp2::regex::char_matcher_logic<char,'d','d','D'>>,::cpp2::regex::group_matcher_end_logic<char,2>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_252 {}; private: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,3,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::class_matcher_logic<char,false,::cpp2::regex::single_class_entry<char,'b'>,::cpp2::regex::single_class_entry<char,'c'>>,0,-1,true,false,'*'>>,::cpp2::regex::group_matcher_end_logic<char,1>>,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,2,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'c','c','C'>,1,-1,true,false,'+'>,::cpp2::regex::char_matcher_logic<char,'d','d','D'>>,::cpp2::regex::group_matcher_end_logic<char,2>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_253 {}; private: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::class_matcher_logic<char,false,::cpp2::regex::single_class_entry<char,'b'>,::cpp2::regex::single_class_entry<char,'c'>,::cpp2::regex::single_class_entry<char,'d'>>,0,-1,true,false,'*'>,::cpp2::regex::char_matcher_logic<char,'d','d','D'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>,::cpp2::regex::char_matcher_logic<char,'d','d','D'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>,::cpp2::regex::char_matcher_logic<char,'d','d','D'>,::cpp2::regex::char_matcher_logic<char,'e','e','E'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_254 {}; private: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::class_matcher_logic<char,false,::cpp2::regex::single_class_entry<char,'b'>,::cpp2::regex::single_class_entry<char,'c'>,::cpp2::regex::single_class_entry<char,'d'>>,1,-1,true,false,'+'>,::cpp2::regex::char_matcher_logic<char,'d','d','D'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>,::cpp2::regex::char_matcher_logic<char,'d','d','D'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>,::cpp2::regex::char_matcher_logic<char,'d','d','D'>,::cpp2::regex::char_matcher_logic<char,'e','e','E'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_255 {}; private: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,2,1,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,"">,::cpp2::regex::alternative_matcher_logic<char,0,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>>>,::cpp2::regex::group_matcher_end_logic<char,1>>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,0,-1,true,false,'*'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_256 {}; private: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,5,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,2,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>>,::cpp2::regex::group_matcher_end_logic<char,2>>,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,3,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>>,::cpp2::regex::group_matcher_end_logic<char,3>>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,1>>,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,4,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'d','d','D'>>,::cpp2::regex::group_matcher_end_logic<char,4>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_257 {}; private: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::class_matcher_logic<char,false,::cpp2::regex::range_class_entry<char,'a','z'>,::cpp2::regex::range_class_entry<char,'A','Z'>,::cpp2::regex::single_class_entry<char,'_'>>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::class_matcher_logic<char,false,::cpp2::regex::range_class_entry<char,'a','z'>,::cpp2::regex::range_class_entry<char,'A','Z'>,::cpp2::regex::range_class_entry<char,'0','9'>,::cpp2::regex::single_class_entry<char,'_'>>,0,-1,true,false,'*'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_258 {}; private: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,2,2,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::alternative_matcher_logic<char,1,::cpp2::regex::matcher_list<char,::cpp2::regex::line_start_matcher_logic<char,true>,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,"">,::cpp2::regex::alternative_matcher_logic<char,0,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'c','c','C'>,1,-1,true,false,'+'>>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::class_matcher_logic<char,false,::cpp2::regex::single_class_entry<char,'e'>,::cpp2::regex::single_class_entry<char,'h'>>>>,::cpp2::regex::group_matcher_end_logic<char,1>>,::cpp2::regex::char_matcher_logic<char,'g','g','G'>>,::cpp2::regex::matcher_list<char,::cpp2::regex::any_matcher_logic<char>,::cpp2::regex::char_matcher_logic<char,'h','h','H'>,::cpp2::regex::line_end_matcher_logic<char,true,false>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_259 {}; private: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::range_matcher_logic<char,::cpp2::regex::any_matcher_logic<char>,1,1,true,false>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_26 {}; private: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,3,2,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,"">,::cpp2::regex::alternative_matcher_logic<char,1,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'c','c','C'>,1,-1,true,false,'+'>,::cpp2::regex::char_matcher_logic<char,'d','d','D'>,::cpp2::regex::line_end_matcher_logic<char,true,false>>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'e','e','E'>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'f','f','F'>,0,-1,true,false,'*'>,::cpp2::regex::char_matcher_logic<char,'g','g','G'>,::cpp2::regex::any_matcher_logic<char>>,::cpp2::regex::matcher_list<char,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'h','h','H'>,0,1,true,false,'?'>,::cpp2::regex::char_matcher_logic<char,'i','i','I'>,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,2,"">,::cpp2::regex::alternative_matcher_logic<char,0,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'j','j','J'>>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'k','k','K'>>>,::cpp2::regex::group_matcher_end_logic<char,2>>>>,::cpp2::regex::group_matcher_end_logic<char,1>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_260 {}; private: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,3,2,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,"">,::cpp2::regex::alternative_matcher_logic<char,1,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'c','c','C'>,1,-1,true,false,'+'>,::cpp2::regex::char_matcher_logic<char,'d','d','D'>,::cpp2::regex::line_end_matcher_logic<char,true,false>>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'e','e','E'>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'f','f','F'>,0,-1,true,false,'*'>,::cpp2::regex::char_matcher_logic<char,'g','g','G'>,::cpp2::regex::any_matcher_logic<char>>,::cpp2::regex::matcher_list<char,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'h','h','H'>,0,1,true,false,'?'>,::cpp2::regex::char_matcher_logic<char,'i','i','I'>,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,2,"">,::cpp2::regex::alternative_matcher_logic<char,0,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'j','j','J'>>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'k','k','K'>>>,::cpp2::regex::group_matcher_end_logic<char,2>>>>,::cpp2::regex::group_matcher_end_logic<char,1>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_261 {}; private: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,3,2,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,"">,::cpp2::regex::alternative_matcher_logic<char,1,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'c','c','C'>,1,-1,true,false,'+'>,::cpp2::regex::char_matcher_logic<char,'d','d','D'>,::cpp2::regex::line_end_matcher_logic<char,true,false>>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'e','e','E'>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'f','f','F'>,0,-1,true,false,'*'>,::cpp2::regex::char_matcher_logic<char,'g','g','G'>,::cpp2::regex::any_matcher_logic<char>>,::cpp2::regex::matcher_list<char,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'h','h','H'>,0,1,true,false,'?'>,::cpp2::regex::char_matcher_logic<char,'i','i','I'>,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,2,"">,::cpp2::regex::alternative_matcher_logic<char,0,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'j','j','J'>>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'k','k','K'>>>,::cpp2::regex::group_matcher_end_logic<char,2>>>>,::cpp2::regex::group_matcher_end_logic<char,1>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_262 {}; private: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,3,2,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,"">,::cpp2::regex::alternative_matcher_logic<char,1,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'c','c','C'>,1,-1,true,false,'+'>,::cpp2::regex::char_matcher_logic<char,'d','d','D'>,::cpp2::regex::line_end_matcher_logic<char,true,false>>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'e','e','E'>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'f','f','F'>,0,-1,true,false,'*'>,::cpp2::regex::char_matcher_logic<char,'g','g','G'>,::cpp2::regex::any_matcher_logic<char>>,::cpp2::regex::matcher_list<char,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'h','h','H'>,0,1,true,false,'?'>,::cpp2::regex::char_matcher_logic<char,'i','i','I'>,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,2,"">,::cpp2::regex::alternative_matcher_logic<char,0,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'j','j','J'>>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'k','k','K'>>>,::cpp2::regex::group_matcher_end_logic<char,2>>>>,::cpp2::regex::group_matcher_end_logic<char,1>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_263 {}; private: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,3,2,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,"">,::cpp2::regex::alternative_matcher_logic<char,1,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'c','c','C'>,1,-1,true,false,'+'>,::cpp2::regex::char_matcher_logic<char,'d','d','D'>,::cpp2::regex::line_end_matcher_logic<char,true,false>>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'e','e','E'>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'f','f','F'>,0,-1,true,false,'*'>,::cpp2::regex::char_matcher_logic<char,'g','g','G'>,::cpp2::regex::any_matcher_logic<char>>,::cpp2::regex::matcher_list<char,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'h','h','H'>,0,1,true,false,'?'>,::cpp2::regex::char_matcher_logic<char,'i','i','I'>,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,2,"">,::cpp2::regex::alternative_matcher_logic<char,0,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'j','j','J'>>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'k','k','K'>>>,::cpp2::regex::group_matcher_end_logic<char,2>>>>,::cpp2::regex::group_matcher_end_logic<char,1>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_264 {}; private: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,11,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,2,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,3,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,4,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,5,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,6,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,7,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,8,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,9,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,10,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>>,::cpp2::regex::group_matcher_end_logic<char,10>>>,::cpp2::regex::group_matcher_end_logic<char,9>>>,::cpp2::regex::group_matcher_end_logic<char,8>>>,::cpp2::regex::group_matcher_end_logic<char,7>>>,::cpp2::regex::group_matcher_end_logic<char,6>>>,::cpp2::regex::group_matcher_end_logic<char,5>>>,::cpp2::regex::group_matcher_end_logic<char,4>>>,::cpp2::regex::group_matcher_end_logic<char,3>>>,::cpp2::regex::group_matcher_end_logic<char,2>>>,::cpp2::regex::group_matcher_end_logic<char,1>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_265 {}; private: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,11,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,2,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,3,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,4,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,5,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,6,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,7,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,8,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,9,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,10,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>>,::cpp2::regex::group_matcher_end_logic<char,10>>>,::cpp2::regex::group_matcher_end_logic<char,9>>>,::cpp2::regex::group_matcher_end_logic<char,8>>>,::cpp2::regex::group_matcher_end_logic<char,7>>>,::cpp2::regex::group_matcher_end_logic<char,6>>>,::cpp2::regex::group_matcher_end_logic<char,5>>>,::cpp2::regex::group_matcher_end_logic<char,4>>>,::cpp2::regex::group_matcher_end_logic<char,3>>>,::cpp2::regex::group_matcher_end_logic<char,2>>>,::cpp2::regex::group_matcher_end_logic<char,1>>,::cpp2::regex::group_ref_matcher_logic<char,10,"\\10">>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_266 {}; private: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,10,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,2,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,3,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,4,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,5,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,6,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,7,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,8,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,9,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>>,::cpp2::regex::group_matcher_end_logic<char,9>>>,::cpp2::regex::group_matcher_end_logic<char,8>>>,::cpp2::regex::group_matcher_end_logic<char,7>>>,::cpp2::regex::group_matcher_end_logic<char,6>>>,::cpp2::regex::group_matcher_end_logic<char,5>>>,::cpp2::regex::group_matcher_end_logic<char,4>>>,::cpp2::regex::group_matcher_end_logic<char,3>>>,::cpp2::regex::group_matcher_end_logic<char,2>>>,::cpp2::regex::group_matcher_end_logic<char,1>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_267 {}; private: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'m','m','M'>,::cpp2::regex::char_matcher_logic<char,'u','u','U'>,::cpp2::regex::char_matcher_logic<char,'l','l','L'>,::cpp2::regex::char_matcher_logic<char,'t','t','T'>,::cpp2::regex::char_matcher_logic<char,'i','i','I'>,::cpp2::regex::char_matcher_logic<char,'p','p','P'>,::cpp2::regex::char_matcher_logic<char,'l','l','L'>,::cpp2::regex::char_matcher_logic<char,'e','e','E'>,::cpp2::regex::char_matcher_logic<char,' ',' ',' '>,::cpp2::regex::char_matcher_logic<char,'w','w','W'>,::cpp2::regex::char_matcher_logic<char,'o','o','O'>,::cpp2::regex::char_matcher_logic<char,'r','r','R'>,::cpp2::regex::char_matcher_logic<char,'d','d','D'>,::cpp2::regex::char_matcher_logic<char,'s','s','S'>,::cpp2::regex::char_matcher_logic<char,' ',' ',' '>,::cpp2::regex::char_matcher_logic<char,'o','o','O'>,::cpp2::regex::char_matcher_logic<char,'f','f','F'>,::cpp2::regex::char_matcher_logic<char,' ',' ',' '>,::cpp2::regex::char_matcher_logic<char,'t','t','T'>,::cpp2::regex::char_matcher_logic<char,'e','e','E'>,::cpp2::regex::char_matcher_logic<char,'x','x','X'>,::cpp2::regex::char_matcher_logic<char,'t','t','T'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_268 {}; private: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'m','m','M'>,::cpp2::regex::char_matcher_logic<char,'u','u','U'>,::cpp2::regex::char_matcher_logic<char,'l','l','L'>,::cpp2::regex::char_matcher_logic<char,'t','t','T'>,::cpp2::regex::char_matcher_logic<char,'i','i','I'>,::cpp2::regex::char_matcher_logic<char,'p','p','P'>,::cpp2::regex::char_matcher_logic<char,'l','l','L'>,::cpp2::regex::char_matcher_logic<char,'e','e','E'>,::cpp2::regex::char_matcher_logic<char,' ',' ',' '>,::cpp2::regex::char_matcher_logic<char,'w','w','W'>,::cpp2::regex::char_matcher_logic<char,'o','o','O'>,::cpp2::regex::char_matcher_logic<char,'r','r','R'>,::cpp2::regex::char_matcher_logic<char,'d','d','D'>,::cpp2::regex::char_matcher_logic<char,'s','s','S'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_269 {}; private: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::range_matcher_logic<char,::cpp2::regex::any_matcher_logic<char>,3,4,true,false>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_27 {}; private: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,3,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::any_matcher_logic<char>,0,-1,true,false,'*'>>,::cpp2::regex::group_matcher_end_logic<char,1>>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,2,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::any_matcher_logic<char>,0,-1,true,false,'*'>>,::cpp2::regex::group_matcher_end_logic<char,2>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_270 {}; private: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,3,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::escaped_char_matcher_logic<char,'(','(','('>,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::any_matcher_logic<char>,0,-1,true,false,'*'>>,::cpp2::regex::group_matcher_end_logic<char,1>>,::cpp2::regex::char_matcher_logic<char,',',',',','>,::cpp2::regex::char_matcher_logic<char,' ',' ',' '>,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,2,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::any_matcher_logic<char>,0,-1,true,false,'*'>>,::cpp2::regex::group_matcher_end_logic<char,2>>,::cpp2::regex::escaped_char_matcher_logic<char,')',')',')'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_271 {}; private: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::class_matcher_logic<char,false,::cpp2::regex::single_class_entry<char,'k'>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_272 {}; private: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>,::cpp2::regex::char_matcher_logic<char,'d','d','D'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_273 {}; private: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,2,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,1>>,::cpp2::regex::char_matcher_logic<char,'d','d','D'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_274 {}; private: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::class_matcher_logic<char,false,::cpp2::regex::single_class_entry<char,'-'>>,0,1,true,false,'?'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_275 {}; private: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,2,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,1>>,::cpp2::regex::group_ref_matcher_logic<char,1,"\\1">>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_276 {}; private: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,2,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::class_matcher_logic<char,false,::cpp2::regex::range_class_entry<char,'a','c'>>,0,-1,true,false,'*'>>,::cpp2::regex::group_matcher_end_logic<char,1>>,::cpp2::regex::group_ref_matcher_logic<char,1,"\\1">>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_277 {}; private: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,1,-1,true,true,'+'>,::cpp2::regex::char_matcher_logic<char,'a','a','A'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_278 {}; private: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,0,-1,true,true,'*'>,::cpp2::regex::char_matcher_logic<char,'a','a','A'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_279 {}; private: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::range_matcher_logic<char,::cpp2::regex::any_matcher_logic<char>,3,4,true,false>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_28 {}; private: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,1,5,true,false>,1,-1,true,false,'+'>,::cpp2::regex::char_matcher_logic<char,'a','a','A'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_280 {}; private: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,0,1,true,true,'?'>,::cpp2::regex::char_matcher_logic<char,'a','a','A'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_281 {}; private: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,1,-1,true,true,'+'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_282 {}; private: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,0,-1,true,true,'*'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_283 {}; private: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,1,5,true,false>,1,-1,true,false,'+'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_284 {}; private: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,0,1,true,true,'?'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_285 {}; private: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'f','f','F'>,::cpp2::regex::char_matcher_logic<char,'o','o','O'>,::cpp2::regex::char_matcher_logic<char,'o','o','O'>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,1,-1,true,true,'+'>,::cpp2::regex::char_matcher_logic<char,'a','a','A'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_286 {}; private: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'f','f','F'>,::cpp2::regex::char_matcher_logic<char,'o','o','O'>,::cpp2::regex::char_matcher_logic<char,'o','o','O'>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,0,-1,true,true,'*'>,::cpp2::regex::char_matcher_logic<char,'a','a','A'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_287 {}; private: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'f','f','F'>,::cpp2::regex::char_matcher_logic<char,'o','o','O'>,::cpp2::regex::char_matcher_logic<char,'o','o','O'>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,1,5,true,false>,1,-1,true,false,'+'>,::cpp2::regex::char_matcher_logic<char,'a','a','A'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_288 {}; private: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'f','f','F'>,::cpp2::regex::char_matcher_logic<char,'o','o','O'>,::cpp2::regex::char_matcher_logic<char,'o','o','O'>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,0,1,true,true,'?'>,::cpp2::regex::char_matcher_logic<char,'a','a','A'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_289 {}; private: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::range_matcher_logic<char,::cpp2::regex::any_matcher_logic<char>,3,4,true,false>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_29 {}; private: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'f','f','F'>,::cpp2::regex::char_matcher_logic<char,'o','o','O'>,::cpp2::regex::char_matcher_logic<char,'o','o','O'>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,1,-1,true,true,'+'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_290 {}; private: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'f','f','F'>,::cpp2::regex::char_matcher_logic<char,'o','o','O'>,::cpp2::regex::char_matcher_logic<char,'o','o','O'>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,0,-1,true,true,'*'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_291 {}; private: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'f','f','F'>,::cpp2::regex::char_matcher_logic<char,'o','o','O'>,::cpp2::regex::char_matcher_logic<char,'o','o','O'>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,1,5,true,false>,1,-1,true,false,'+'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_292 {}; private: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'f','f','F'>,::cpp2::regex::char_matcher_logic<char,'o','o','O'>,::cpp2::regex::char_matcher_logic<char,'o','o','O'>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,0,1,true,true,'?'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_293 {}; private: ::cpp2::regex::regular_expression<char,0,3,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'A','a','A'>>,::cpp2::regex::group_matcher_end_logic<char,1>>,1,-1,true,true,'+'>,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,2,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'A','a','A'>>,::cpp2::regex::group_matcher_end_logic<char,2>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_294 {}; private: ::cpp2::regex::regular_expression<char,0,3,2,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,"">,::cpp2::regex::alternative_matcher_logic<char,0,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'A','a','A'>>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'B','b','B'>>>,::cpp2::regex::group_matcher_end_logic<char,1>>,1,-1,true,true,'+'>,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,2,"">,::cpp2::regex::alternative_matcher_logic<char,1,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'A','a','A'>>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'B','b','B'>>>,::cpp2::regex::group_matcher_end_logic<char,2>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_295 {}; private: ::cpp2::regex::regular_expression<char,0,3,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'A','a','A'>>,::cpp2::regex::group_matcher_end_logic<char,1>>,0,-1,true,true,'*'>,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,2,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'A','a','A'>>,::cpp2::regex::group_matcher_end_logic<char,2>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_296 {}; private: ::cpp2::regex::regular_expression<char,0,3,2,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,"">,::cpp2::regex::alternative_matcher_logic<char,0,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'A','a','A'>>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'B','b','B'>>>,::cpp2::regex::group_matcher_end_logic<char,1>>,0,-1,true,true,'*'>,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,2,"">,::cpp2::regex::alternative_matcher_logic<char,1,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'A','a','A'>>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'B','b','B'>>>,::cpp2::regex::group_matcher_end_logic<char,2>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_297 {}; private: ::cpp2::regex::regular_expression<char,0,3,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::range_matcher_logic<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'A','a','A'>>,::cpp2::regex::group_matcher_end_logic<char,1>>,1,5,true,false>,1,-1,true,false,'+'>,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,2,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'A','a','A'>>,::cpp2::regex::group_matcher_end_logic<char,2>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_298 {}; private: ::cpp2::regex::regular_expression<char,0,3,2,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::range_matcher_logic<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,"">,::cpp2::regex::alternative_matcher_logic<char,0,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'A','a','A'>>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'B','b','B'>>>,::cpp2::regex::group_matcher_end_logic<char,1>>,1,5,true,false>,1,-1,true,false,'+'>,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,2,"">,::cpp2::regex::alternative_matcher_logic<char,1,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'A','a','A'>>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'B','b','B'>>>,::cpp2::regex::group_matcher_end_logic<char,2>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_299 {}; private: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_3 {}; private: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::range_matcher_logic<char,::cpp2::regex::named_class_no_new_line<char>,1,1,true,false>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_30 {}; private: ::cpp2::regex::regular_expression<char,0,3,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'A','a','A'>>,::cpp2::regex::group_matcher_end_logic<char,1>>,0,1,true,true,'?'>,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,2,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'A','a','A'>>,::cpp2::regex::group_matcher_end_logic<char,2>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_300 {}; private: ::cpp2::regex::regular_expression<char,0,3,2,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,"">,::cpp2::regex::alternative_matcher_logic<char,0,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'A','a','A'>>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'B','b','B'>>>,::cpp2::regex::group_matcher_end_logic<char,1>>,0,1,true,true,'?'>,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,2,"">,::cpp2::regex::alternative_matcher_logic<char,1,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'A','a','A'>>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'B','b','B'>>>,::cpp2::regex::group_matcher_end_logic<char,2>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_301 {}; private: ::cpp2::regex::regular_expression<char,0,2,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'A','a','A'>>,::cpp2::regex::group_matcher_end_logic<char,1>>,1,-1,true,true,'+'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_302 {}; private: ::cpp2::regex::regular_expression<char,0,2,1,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,"">,::cpp2::regex::alternative_matcher_logic<char,0,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'A','a','A'>>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'B','b','B'>>>,::cpp2::regex::group_matcher_end_logic<char,1>>,1,-1,true,true,'+'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_303 {}; private: ::cpp2::regex::regular_expression<char,0,2,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'A','a','A'>>,::cpp2::regex::group_matcher_end_logic<char,1>>,0,-1,true,true,'*'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_304 {}; private: ::cpp2::regex::regular_expression<char,0,2,1,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,"">,::cpp2::regex::alternative_matcher_logic<char,0,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'A','a','A'>>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'B','b','B'>>>,::cpp2::regex::group_matcher_end_logic<char,1>>,0,-1,true,true,'*'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_305 {}; private: ::cpp2::regex::regular_expression<char,0,2,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::range_matcher_logic<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'A','a','A'>>,::cpp2::regex::group_matcher_end_logic<char,1>>,1,5,true,false>,1,-1,true,false,'+'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_306 {}; private: ::cpp2::regex::regular_expression<char,0,2,1,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::range_matcher_logic<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,"">,::cpp2::regex::alternative_matcher_logic<char,0,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'A','a','A'>>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'B','b','B'>>>,::cpp2::regex::group_matcher_end_logic<char,1>>,1,5,true,false>,1,-1,true,false,'+'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_307 {}; private: ::cpp2::regex::regular_expression<char,0,2,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'A','a','A'>>,::cpp2::regex::group_matcher_end_logic<char,1>>,0,1,true,true,'?'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_308 {}; private: ::cpp2::regex::regular_expression<char,0,2,1,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,"">,::cpp2::regex::alternative_matcher_logic<char,0,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'A','a','A'>>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'B','b','B'>>>,::cpp2::regex::group_matcher_end_logic<char,1>>,0,1,true,true,'?'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_309 {}; private: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::range_matcher_logic<char,::cpp2::regex::named_class_no_new_line<char>,1,1,true,false>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_31 {}; private: ::cpp2::regex::regular_expression<char,0,3,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'f','f','F'>,::cpp2::regex::char_matcher_logic<char,'o','o','O'>,::cpp2::regex::char_matcher_logic<char,'o','o','O'>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'A','a','A'>>,::cpp2::regex::group_matcher_end_logic<char,1>>,1,-1,true,true,'+'>,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,2,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'A','a','A'>>,::cpp2::regex::group_matcher_end_logic<char,2>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_310 {}; private: ::cpp2::regex::regular_expression<char,0,3,2,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'f','f','F'>,::cpp2::regex::char_matcher_logic<char,'o','o','O'>,::cpp2::regex::char_matcher_logic<char,'o','o','O'>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,"">,::cpp2::regex::alternative_matcher_logic<char,0,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'A','a','A'>>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'B','b','B'>>>,::cpp2::regex::group_matcher_end_logic<char,1>>,1,-1,true,true,'+'>,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,2,"">,::cpp2::regex::alternative_matcher_logic<char,1,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'A','a','A'>>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'B','b','B'>>>,::cpp2::regex::group_matcher_end_logic<char,2>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_311 {}; private: ::cpp2::regex::regular_expression<char,0,3,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'f','f','F'>,::cpp2::regex::char_matcher_logic<char,'o','o','O'>,::cpp2::regex::char_matcher_logic<char,'o','o','O'>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'A','a','A'>>,::cpp2::regex::group_matcher_end_logic<char,1>>,0,-1,true,true,'*'>,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,2,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'A','a','A'>>,::cpp2::regex::group_matcher_end_logic<char,2>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_312 {}; private: ::cpp2::regex::regular_expression<char,0,3,2,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'f','f','F'>,::cpp2::regex::char_matcher_logic<char,'o','o','O'>,::cpp2::regex::char_matcher_logic<char,'o','o','O'>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,"">,::cpp2::regex::alternative_matcher_logic<char,0,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'A','a','A'>>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'B','b','B'>>>,::cpp2::regex::group_matcher_end_logic<char,1>>,0,-1,true,true,'*'>,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,2,"">,::cpp2::regex::alternative_matcher_logic<char,1,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'A','a','A'>>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'B','b','B'>>>,::cpp2::regex::group_matcher_end_logic<char,2>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_313 {}; private: ::cpp2::regex::regular_expression<char,0,3,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'f','f','F'>,::cpp2::regex::char_matcher_logic<char,'o','o','O'>,::cpp2::regex::char_matcher_logic<char,'o','o','O'>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::range_matcher_logic<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'A','a','A'>>,::cpp2::regex::group_matcher_end_logic<char,1>>,1,5,true,false>,1,-1,true,false,'+'>,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,2,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'A','a','A'>>,::cpp2::regex::group_matcher_end_logic<char,2>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_314 {}; private: ::cpp2::regex::regular_expression<char,0,3,2,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'f','f','F'>,::cpp2::regex::char_matcher_logic<char,'o','o','O'>,::cpp2::regex::char_matcher_logic<char,'o','o','O'>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::range_matcher_logic<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,"">,::cpp2::regex::alternative_matcher_logic<char,0,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'A','a','A'>>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'B','b','B'>>>,::cpp2::regex::group_matcher_end_logic<char,1>>,1,5,true,false>,1,-1,true,false,'+'>,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,2,"">,::cpp2::regex::alternative_matcher_logic<char,1,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'A','a','A'>>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'B','b','B'>>>,::cpp2::regex::group_matcher_end_logic<char,2>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_315 {}; private: ::cpp2::regex::regular_expression<char,0,3,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'f','f','F'>,::cpp2::regex::char_matcher_logic<char,'o','o','O'>,::cpp2::regex::char_matcher_logic<char,'o','o','O'>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'A','a','A'>>,::cpp2::regex::group_matcher_end_logic<char,1>>,0,1,true,true,'?'>,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,2,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'A','a','A'>>,::cpp2::regex::group_matcher_end_logic<char,2>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_316 {}; private: ::cpp2::regex::regular_expression<char,0,3,2,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'f','f','F'>,::cpp2::regex::char_matcher_logic<char,'o','o','O'>,::cpp2::regex::char_matcher_logic<char,'o','o','O'>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,"">,::cpp2::regex::alternative_matcher_logic<char,0,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'A','a','A'>>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'B','b','B'>>>,::cpp2::regex::group_matcher_end_logic<char,1>>,0,1,true,true,'?'>,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,2,"">,::cpp2::regex::alternative_matcher_logic<char,1,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'A','a','A'>>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'B','b','B'>>>,::cpp2::regex::group_matcher_end_logic<char,2>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_317 {}; private: ::cpp2::regex::regular_expression<char,0,2,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'f','f','F'>,::cpp2::regex::char_matcher_logic<char,'o','o','O'>,::cpp2::regex::char_matcher_logic<char,'o','o','O'>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'A','a','A'>>,::cpp2::regex::group_matcher_end_logic<char,1>>,1,-1,true,true,'+'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_318 {}; private: ::cpp2::regex::regular_expression<char,0,2,1,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'f','f','F'>,::cpp2::regex::char_matcher_logic<char,'o','o','O'>,::cpp2::regex::char_matcher_logic<char,'o','o','O'>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,"">,::cpp2::regex::alternative_matcher_logic<char,0,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'A','a','A'>>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'B','b','B'>>>,::cpp2::regex::group_matcher_end_logic<char,1>>,1,-1,true,true,'+'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_319 {}; private: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::range_matcher_logic<char,::cpp2::regex::named_class_no_new_line<char>,1,1,true,false>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_32 {}; private: ::cpp2::regex::regular_expression<char,0,2,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'f','f','F'>,::cpp2::regex::char_matcher_logic<char,'o','o','O'>,::cpp2::regex::char_matcher_logic<char,'o','o','O'>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'A','a','A'>>,::cpp2::regex::group_matcher_end_logic<char,1>>,0,-1,true,true,'*'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_320 {}; private: ::cpp2::regex::regular_expression<char,0,2,1,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'f','f','F'>,::cpp2::regex::char_matcher_logic<char,'o','o','O'>,::cpp2::regex::char_matcher_logic<char,'o','o','O'>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,"">,::cpp2::regex::alternative_matcher_logic<char,0,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'A','a','A'>>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'B','b','B'>>>,::cpp2::regex::group_matcher_end_logic<char,1>>,0,-1,true,true,'*'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_321 {}; private: ::cpp2::regex::regular_expression<char,0,2,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'f','f','F'>,::cpp2::regex::char_matcher_logic<char,'o','o','O'>,::cpp2::regex::char_matcher_logic<char,'o','o','O'>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::range_matcher_logic<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'A','a','A'>>,::cpp2::regex::group_matcher_end_logic<char,1>>,1,5,true,false>,1,-1,true,false,'+'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_322 {}; private: ::cpp2::regex::regular_expression<char,0,2,1,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'f','f','F'>,::cpp2::regex::char_matcher_logic<char,'o','o','O'>,::cpp2::regex::char_matcher_logic<char,'o','o','O'>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::range_matcher_logic<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,"">,::cpp2::regex::alternative_matcher_logic<char,0,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'A','a','A'>>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'B','b','B'>>>,::cpp2::regex::group_matcher_end_logic<char,1>>,1,5,true,false>,1,-1,true,false,'+'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_323 {}; private: ::cpp2::regex::regular_expression<char,0,2,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'f','f','F'>,::cpp2::regex::char_matcher_logic<char,'o','o','O'>,::cpp2::regex::char_matcher_logic<char,'o','o','O'>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'A','a','A'>>,::cpp2::regex::group_matcher_end_logic<char,1>>,0,1,true,true,'?'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_324 {}; private: ::cpp2::regex::regular_expression<char,0,2,1,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'f','f','F'>,::cpp2::regex::char_matcher_logic<char,'o','o','O'>,::cpp2::regex::char_matcher_logic<char,'o','o','O'>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,"">,::cpp2::regex::alternative_matcher_logic<char,0,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'A','a','A'>>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'B','b','B'>>>,::cpp2::regex::group_matcher_end_logic<char,1>>,0,1,true,true,'?'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_325 {}; private: ::cpp2::regex::regular_expression<char,0,2,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'f','f','F'>,::cpp2::regex::char_matcher_logic<char,'o','o','O'>,::cpp2::regex::char_matcher_logic<char,'o','o','O'>,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::named_class_hor_space<char>,1,-1,true,false,'+'>>,::cpp2::regex::group_matcher_end_logic<char,1>>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'r','r','R'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_326 {}; private: ::cpp2::regex::regular_expression<char,0,3,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::named_class_not_hor_space<char>,1,-1,true,false,'+'>>,::cpp2::regex::group_matcher_end_logic<char,1>>,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,2,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::named_class_hor_space<char>>,::cpp2::regex::group_matcher_end_logic<char,2>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_327 {}; private: ::cpp2::regex::regular_expression<char,0,3,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::named_class_hor_space<char>,1,-1,true,false,'+'>>,::cpp2::regex::group_matcher_end_logic<char,1>>,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,2,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::named_class_not_hor_space<char>>,::cpp2::regex::group_matcher_end_logic<char,2>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_328 {}; private: ::cpp2::regex::regular_expression<char,0,2,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'f','f','F'>,::cpp2::regex::char_matcher_logic<char,'o','o','O'>,::cpp2::regex::char_matcher_logic<char,'o','o','O'>,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::named_class_hor_space<char>>,::cpp2::regex::group_matcher_end_logic<char,1>>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'r','r','R'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_329 {}; private: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::range_matcher_logic<char,::cpp2::regex::named_class_no_new_line<char>,3,4,true,false>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_33 {}; private: ::cpp2::regex::regular_expression<char,0,3,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::named_class_not_hor_space<char>>,::cpp2::regex::group_matcher_end_logic<char,1>>,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,2,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::named_class_hor_space<char>>,::cpp2::regex::group_matcher_end_logic<char,2>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_330 {}; private: ::cpp2::regex::regular_expression<char,0,3,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::named_class_hor_space<char>>,::cpp2::regex::group_matcher_end_logic<char,1>>,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,2,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::named_class_not_hor_space<char>>,::cpp2::regex::group_matcher_end_logic<char,2>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_331 {}; private: ::cpp2::regex::regular_expression<char,0,2,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'f','f','F'>,::cpp2::regex::char_matcher_logic<char,'o','o','O'>,::cpp2::regex::char_matcher_logic<char,'o','o','O'>,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::named_class_ver_space<char>,1,-1,true,false,'+'>>,::cpp2::regex::group_matcher_end_logic<char,1>>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'r','r','R'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_332 {}; private: ::cpp2::regex::regular_expression<char,0,3,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::named_class_not_ver_space<char>,1,-1,true,false,'+'>>,::cpp2::regex::group_matcher_end_logic<char,1>>,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,2,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::named_class_ver_space<char>>,::cpp2::regex::group_matcher_end_logic<char,2>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_333 {}; private: ::cpp2::regex::regular_expression<char,0,3,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::named_class_ver_space<char>,1,-1,true,false,'+'>>,::cpp2::regex::group_matcher_end_logic<char,1>>,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,2,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::named_class_not_ver_space<char>>,::cpp2::regex::group_matcher_end_logic<char,2>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_334 {}; private: ::cpp2::regex::regular_expression<char,0,2,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'f','f','F'>,::cpp2::regex::char_matcher_logic<char,'o','o','O'>,::cpp2::regex::char_matcher_logic<char,'o','o','O'>,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::named_class_ver_space<char>>,::cpp2::regex::group_matcher_end_logic<char,1>>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'r','r','R'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_335 {}; private: ::cpp2::regex::regular_expression<char,0,3,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::named_class_not_ver_space<char>>,::cpp2::regex::group_matcher_end_logic<char,1>>,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,2,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::named_class_ver_space<char>>,::cpp2::regex::group_matcher_end_logic<char,2>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_336 {}; private: ::cpp2::regex::regular_expression<char,0,3,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::named_class_ver_space<char>>,::cpp2::regex::group_matcher_end_logic<char,1>>,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,2,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::named_class_not_ver_space<char>>,::cpp2::regex::group_matcher_end_logic<char,2>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_337 {}; private: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'f','f','F'>,::cpp2::regex::char_matcher_logic<char,'o','o','O'>,::cpp2::regex::char_matcher_logic<char,'o','o','O'>,::cpp2::regex::global_group_reset<char>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'r','r','R'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_338 {}; private: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'f','f','F'>,::cpp2::regex::char_matcher_logic<char,'o','o','O'>,::cpp2::regex::char_matcher_logic<char,'o','o','O'>,::cpp2::regex::named_matcher_logic<char,"\\t",::cpp2::regex::char_matcher_logic<char,'\t','\t','\t'>>,::cpp2::regex::named_matcher_logic<char,"\\n",::cpp2::regex::char_matcher_logic<char,'\n','\n','\n'>>,::cpp2::regex::named_matcher_logic<char,"\\r",::cpp2::regex::char_matcher_logic<char,'\r','\r','\r'>>,::cpp2::regex::named_matcher_logic<char,"\\f",::cpp2::regex::char_matcher_logic<char,'\f','\f','\f'>>,::cpp2::regex::named_matcher_logic<char,"\\a",::cpp2::regex::char_matcher_logic<char,'\a','\a','\a'>>,::cpp2::regex::named_matcher_logic<char,"\\e",::cpp2::regex::char_matcher_logic<char,'\e','\e','\e'>>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'r','r','R'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_339 {}; private: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::range_matcher_logic<char,::cpp2::regex::named_class_no_new_line<char>,3,4,true,false>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_34 {}; private: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::range_matcher_logic<char,::cpp2::regex::named_class_no_new_line<char>,3,4,true,false>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_35 {}; private: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::range_matcher_logic<char,::cpp2::regex::named_class_no_new_line<char>,3,4,true,false>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_36 {}; private: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,0,-1,true,false>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_37 {}; private: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,0,-1,true,false>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_38 {}; private: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,0,-1,true,false>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_39 {}; private: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_4 {}; private: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,1,-1,true,false,'+'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_40 {}; private: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,1,-1,true,false,'+'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_41 {}; private: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,1,-1,true,false,'+'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_42 {}; private: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,1,-1,true,false,'+'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_43 {}; private: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,1,-1,true,false,'+'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_44 {}; private: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,1,-1,true,false>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_45 {}; private: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,1,-1,true,false,'+'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_46 {}; private: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,1,-1,true,false,'+'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_47 {}; private: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,1,-1,true,false,'+'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_48 {}; private: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,1,-1,true,false>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_49 {}; private: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_5 {}; private: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,1,-1,true,false>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_50 {}; private: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,1,-1,true,false>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_51 {}; private: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,1,3,true,false>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_52 {}; private: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,1,3,true,false>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_53 {}; private: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,1,3,true,false>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_54 {}; private: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,3,4,true,false>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_55 {}; private: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,3,4,true,false>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_56 {}; private: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,3,4,true,false>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_57 {}; private: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,4,5,true,false>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_58 {}; private: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,0,1,true,false,'?'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_59 {}; private: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_6 {}; private: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,0,1,true,false,'?'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_60 {}; private: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,0,1,true,false>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_61 {}; private: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,0,1,true,false,'?'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_62 {}; private: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,0,1,true,false,'?'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_63 {}; private: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,0,1,true,false>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_64 {}; private: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::line_start_matcher_logic<char,true>,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>,::cpp2::regex::line_end_matcher_logic<char,true,false>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_65 {}; private: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::line_start_matcher_logic<char,true>,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>,::cpp2::regex::line_end_matcher_logic<char,true,false>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_66 {}; private: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::line_start_matcher_logic<char,true>,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_67 {}; private: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::line_start_matcher_logic<char,true>,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>,::cpp2::regex::line_end_matcher_logic<char,true,false>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_68 {}; private: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>,::cpp2::regex::line_end_matcher_logic<char,true,false>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_69 {}; private: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_7 {}; private: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>,::cpp2::regex::line_end_matcher_logic<char,true,false>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_70 {}; private: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::line_start_matcher_logic<char,true>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_71 {}; private: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::line_end_matcher_logic<char,true,false>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_72 {}; private: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::any_matcher_logic<char>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_73 {}; private: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::any_matcher_logic<char>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_74 {}; private: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::named_class_no_new_line<char>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_75 {}; private: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::any_matcher_logic<char>,0,-1,true,false,'*'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_76 {}; private: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::named_class_no_new_line<char>,0,-1,true,false,'*'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_77 {}; private: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::any_matcher_logic<char>,0,-1,true,false,'*'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_78 {}; private: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::named_class_no_new_line<char>,0,-1,true,false,'*'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_79 {}; private: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_8 {}; private: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::class_matcher_logic<char,false,::cpp2::regex::single_class_entry<char,'b'>,::cpp2::regex::single_class_entry<char,'c'>>,::cpp2::regex::char_matcher_logic<char,'d','d','D'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_80 {}; private: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::class_matcher_logic<char,false,::cpp2::regex::single_class_entry<char,'b'>,::cpp2::regex::single_class_entry<char,'c'>>,::cpp2::regex::char_matcher_logic<char,'d','d','D'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_81 {}; private: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::class_matcher_logic<char,false,::cpp2::regex::single_class_entry<char,'b'>>,::cpp2::regex::char_matcher_logic<char,'d','d','D'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_82 {}; private: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::class_matcher_logic<char,false,::cpp2::regex::single_class_entry<char,'a'>>,::cpp2::regex::class_matcher_logic<char,false,::cpp2::regex::single_class_entry<char,'b'>>,::cpp2::regex::class_matcher_logic<char,false,::cpp2::regex::single_class_entry<char,'d'>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_83 {}; private: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::any_matcher_logic<char>,::cpp2::regex::class_matcher_logic<char,false,::cpp2::regex::single_class_entry<char,'b'>>,::cpp2::regex::any_matcher_logic<char>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_84 {}; private: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::any_matcher_logic<char>,::cpp2::regex::class_matcher_logic<char,false,::cpp2::regex::single_class_entry<char,'b'>>,::cpp2::regex::any_matcher_logic<char>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_85 {}; private: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::class_matcher_logic<char,false,::cpp2::regex::range_class_entry<char,'b','d'>>,::cpp2::regex::char_matcher_logic<char,'e','e','E'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_86 {}; private: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::class_matcher_logic<char,false,::cpp2::regex::range_class_entry<char,'b','d'>>,::cpp2::regex::char_matcher_logic<char,'e','e','E'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_87 {}; private: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::class_matcher_logic<char,false,::cpp2::regex::range_class_entry<char,'b','d'>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_88 {}; private: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::class_matcher_logic<char,false,::cpp2::regex::single_class_entry<char,'-'>,::cpp2::regex::single_class_entry<char,'b'>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_89 {}; private: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_9 {}; private: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::class_matcher_logic<char,false,::cpp2::regex::single_class_entry<char,'b'>,::cpp2::regex::single_class_entry<char,'-'>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_90 {}; private: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,']',']',']'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_91 {}; private: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::class_matcher_logic<char,false,::cpp2::regex::single_class_entry<char,']'>>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_92 {}; private: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::class_matcher_logic<char,true,::cpp2::regex::single_class_entry<char,'b'>,::cpp2::regex::single_class_entry<char,'c'>>,::cpp2::regex::char_matcher_logic<char,'d','d','D'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_93 {}; private: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::class_matcher_logic<char,true,::cpp2::regex::single_class_entry<char,'b'>,::cpp2::regex::single_class_entry<char,'c'>>,::cpp2::regex::char_matcher_logic<char,'d','d','D'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_94 {}; private: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::class_matcher_logic<char,true,::cpp2::regex::single_class_entry<char,'-'>,::cpp2::regex::single_class_entry<char,'b'>>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_95 {}; private: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::class_matcher_logic<char,true,::cpp2::regex::single_class_entry<char,'-'>,::cpp2::regex::single_class_entry<char,'b'>>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_96 {}; private: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::class_matcher_logic<char,true,::cpp2::regex::single_class_entry<char,']'>,::cpp2::regex::single_class_entry<char,'b'>>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_97 {}; private: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::class_matcher_logic<char,true,::cpp2::regex::single_class_entry<char,']'>,::cpp2::regex::single_class_entry<char,'b'>>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_98 {}; private: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,"">,::cpp2::regex::matcher_list<char,::cpp2::regex::word_boundary_matcher_logic<char,false>,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::word_boundary_matcher_logic<char,false>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_99 {}; 
  public: test_perl_tests() = default;
  public: test_perl_tests(test_perl_tests const&) = delete; /* No 'that' constructor, suppress copy */
  public: auto operator=(test_perl_tests const&) -> void = delete;


#line 1278 "pure2-regex.cpp2"
};
auto main(int const argc_, char** argv_) -> int;

//=== Cpp2 function definitions =================================================

#line 1 "pure2-regex.cpp2"
[[nodiscard]] auto create_result(cpp2::in<std::string> resultExpr, auto const& r) -> std::string{
#line 2 "pure2-regex.cpp2"
  std::string result {""}; 

  auto get_next {[_0 = (&resultExpr)](auto const& iter) mutable -> auto{
  auto start {std::distance(CPP2_UFCS(cbegin)((*cpp2::assert_not_null(_0))), iter)}; 
    auto firstDollar {CPP2_UFCS(find)((*cpp2::assert_not_null(_0)), "$", start)}; 
    auto firstAt {CPP2_UFCS(find)((*cpp2::assert_not_null(_0)), "@", std::move(start))}; 

  auto end {std::min(std::move(firstDollar), std::move(firstAt))}; 
  if (end != std::string::npos) {
   return CPP2_UFCS(cbegin)((*cpp2::assert_not_null(_0))) + std::move(end); 
  }
  else {
   return CPP2_UFCS(cend)((*cpp2::assert_not_null(_0))); 
  }
  }}; 
  auto extract_group_and_advance {[](auto& iter) mutable -> auto{
    auto start {iter}; 

    for( ; std::isdigit(*cpp2::assert_not_null(iter)); ++iter ) {}

    return std::stoi(std::string(std::move(start), iter)); 
  }}; 

  auto iter {CPP2_UFCS(begin)(resultExpr)}; 

  while( iter != CPP2_UFCS(end)(resultExpr) ) {
    auto next {get_next(iter)}; 

    if (next != iter) {
      result += std::string(iter, next);
    }
    if (next != CPP2_UFCS(end)(resultExpr)) {
      if (*cpp2::assert_not_null(next) == '$') {
        ++next;

        if (*cpp2::assert_not_null(next) == '&') {
          ++next;
          result += CPP2_UFCS(group)(r, 0);
        }
        else {if (*cpp2::assert_not_null(next) == '-' || *cpp2::assert_not_null(next) == '+') {
          auto is_start {*cpp2::assert_not_null(next) == '-'}; 
          ++next;
          ++next; // Skip [
          auto group {extract_group_and_advance(next)}; 
          ++next; // Skip ]

          if (is_start) {
            result += std::to_string(CPP2_UFCS(group_start)(r, group));
          }
          else {
            result += std::to_string(CPP2_UFCS(group_end)(r, group));
          }
        }
        else {if (std::isdigit(*cpp2::assert_not_null(next))) {
          auto group {extract_group_and_advance(next)}; 
          result += CPP2_UFCS(group)(r, group);
        }
        else {
          std::cerr << "Not implemented";
        }}}
      }
      else {if (*cpp2::assert_not_null(next) == '@') {
        ++next;

        if (*cpp2::assert_not_null(next) == '-' || *cpp2::assert_not_null(next) == '+') {
          auto i {0}; 
          for( ; cpp2::cmp_less(i,cpp2::unsafe_narrow<int>(CPP2_UFCS(group_number)(r))); ++i ) {
            auto pos {0}; 
            if (*cpp2::assert_not_null(next) == '-') {
              pos = CPP2_UFCS(group_start)(r, i);
            }
            else {
              pos = CPP2_UFCS(group_end)(r, i);
            }
            result +=  std::to_string(pos);
          }
        }
        else {
          std::cerr << "Not implemented";
        }
      }
      else {
        std::cerr << "Not implemented.";
      }}
    }
    iter = next;
  }

  return result; 
}

#line 93 "pure2-regex.cpp2"
template<typename M> auto test(M const& regex, cpp2::in<int> id, cpp2::in<std::string> regex_str, cpp2::in<std::string> str, cpp2::in<std::string> kind, cpp2::in<std::string> resultExpr, 
           cpp2::in<std::string> resultExpected) -> void{

  std::string warning {""}; 
  if (CPP2_UFCS(to_string)(regex) != regex_str) {
    warning = "Warning: Parsed regex does not match.";
  }

  std::string status {"OK"}; 

  auto r {CPP2_UFCS(search)(regex, str)}; 

  if ("y" == kind) {
    if (!(r.matched)) {
      status = "Failure: Regex should apply.";
    }
    else {
      // Have a match check the result

      auto result {create_result(resultExpr, std::move(r))}; 

      if (result != resultExpected) {
        status = { "Failure: Result is wrong. (is: " + cpp2::to_string(std::move(result)) + ")" };
      }
    }
  }
  else {if ("n" == kind) {
    if (std::move(r).matched) {
      status = "Failure: Regex should not apply.";
    }
  }else {
    status = { "Unknown kind '" + cpp2::to_string(kind) + "'" };
  }}

  if (!(CPP2_UFCS(empty)(warning))) {
    warning += " ";
  }
  std::cout << (cpp2::to_string(id) + "_" + cpp2::to_string(kind) + ": " + cpp2::to_string(std::move(status)) + " " + cpp2::to_string(std::move(warning)) + "regex: " + cpp2::to_string(regex_str) + " parsed_regex: " + cpp2::to_string(CPP2_UFCS(to_string)(regex)) + " str: " + cpp2::to_string(str) + " result_expr: " + cpp2::to_string(resultExpr) + " expected_results " + cpp2::to_string(resultExpected)) << std::endl;
}

#line 934 "pure2-regex.cpp2"
  auto test_perl_tests::run() const& -> void{
    std::cout << "Running perl_tests:" << std::endl;
    test(regex_0, 0, "abc", "abc", "y", "$&", "abc");
    test(regex_1, 1, "abc", "abc", "y", "$-[0]", "0");
    test(regex_2, 2, "abc", "abc", "y", "$+[0]", "3");
    test(regex_3, 3, "abc", "xbc", "n", "-", "-");
    test(regex_4, 4, "abc", "axc", "n", "-", "-");
    test(regex_5, 5, "abc", "abx", "n", "-", "-");
    test(regex_6, 6, "abc", "xabcy", "y", "$&", "abc");
    test(regex_7, 7, "abc", "xabcy", "y", "$-[0]", "1");
    test(regex_8, 8, "abc", "xabcy", "y", "$+[0]", "4");
    test(regex_9, 9, "abc", "ababc", "y", "$&", "abc");
    test(regex_10, 10, "abc", "ababc", "y", "$-[0]", "2");
    test(regex_11, 11, "abc", "ababc", "y", "$+[0]", "5");
    test(regex_12, 12, "ab*c", "abc", "y", "$&", "abc");
    test(regex_13, 13, "ab*c", "abc", "y", "$-[0]", "0");
    test(regex_14, 14, "ab*c", "abc", "y", "$+[0]", "3");
    test(regex_15, 15, "ab*bc", "abc", "y", "$&", "abc");
    test(regex_16, 16, "ab*bc", "abc", "y", "$-[0]", "0");
    test(regex_17, 17, "ab*bc", "abc", "y", "$+[0]", "3");
    test(regex_18, 18, "ab*bc", "abbc", "y", "$&", "abbc");
    test(regex_19, 19, "ab*bc", "abbc", "y", "$-[0]", "0");
    test(regex_20, 20, "ab*bc", "abbc", "y", "$+[0]", "4");
    test(regex_21, 21, "ab*bc", "abbbbc", "y", "$&", "abbbbc");
    test(regex_22, 22, "ab*bc", "abbbbc", "y", "$-[0]", "0");
    test(regex_23, 23, "ab*bc", "abbbbc", "y", "$+[0]", "6");
    test(regex_24, 24, ".{1}", "abbbbc", "y", "$&", "a");
    test(regex_25, 25, ".{1}", "abbbbc", "y", "$-[0]", "0");
    test(regex_26, 26, ".{1}", "abbbbc", "y", "$+[0]", "1");
    test(regex_27, 27, ".{3,4}", "abbbbc", "y", "$&", "abbb");
    test(regex_28, 28, ".{3,4}", "abbbbc", "y", "$-[0]", "0");
    test(regex_29, 29, ".{3,4}", "abbbbc", "y", "$+[0]", "4");
    test(regex_30, 30, "\\\\N{1}", "abbbbc", "y", "$&", "a");
    test(regex_31, 31, "\\\\N{1}", "abbbbc", "y", "$-[0]", "0");
    test(regex_32, 32, "\\\\N{1}", "abbbbc", "y", "$+[0]", "1");
    test(regex_33, 33, "\\\\N{3,4}", "abbbbc", "y", "$&", "abbb");
    test(regex_34, 34, "\\\\N{3,4}", "abbbbc", "y", "$-[0]", "0");
    test(regex_35, 35, "\\\\N{3,4}", "abbbbc", "y", "$+[0]", "4");
    test(regex_36, 36, "\\\\N{ 3 , 4 }", "abbbbc", "y", "$+[0]", "4");
    test(regex_37, 37, "ab{0,}bc", "abbbbc", "y", "$&", "abbbbc");
    test(regex_38, 38, "ab{0,}bc", "abbbbc", "y", "$-[0]", "0");
    test(regex_39, 39, "ab{0,}bc", "abbbbc", "y", "$+[0]", "6");
    test(regex_40, 40, "ab+bc", "abbc", "y", "$&", "abbc");
    test(regex_41, 41, "ab+bc", "abbc", "y", "$-[0]", "0");
    test(regex_42, 42, "ab+bc", "abbc", "y", "$+[0]", "4");
    test(regex_43, 43, "ab+bc", "abc", "n", "-", "-");
    test(regex_44, 44, "ab+bc", "abq", "n", "-", "-");
    test(regex_45, 45, "ab{1,}bc", "abq", "n", "-", "-");
    test(regex_46, 46, "ab+bc", "abbbbc", "y", "$&", "abbbbc");
    test(regex_47, 47, "ab+bc", "abbbbc", "y", "$-[0]", "0");
    test(regex_48, 48, "ab+bc", "abbbbc", "y", "$+[0]", "6");
    test(regex_49, 49, "ab{1,}bc", "abbbbc", "y", "$&", "abbbbc");
    test(regex_50, 50, "ab{1,}bc", "abbbbc", "y", "$-[0]", "0");
    test(regex_51, 51, "ab{1,}bc", "abbbbc", "y", "$+[0]", "6");
    test(regex_52, 52, "ab{1,3}bc", "abbbbc", "y", "$&", "abbbbc");
    test(regex_53, 53, "ab{1,3}bc", "abbbbc", "y", "$-[0]", "0");
    test(regex_54, 54, "ab{1,3}bc", "abbbbc", "y", "$+[0]", "6");
    test(regex_55, 55, "ab{3,4}bc", "abbbbc", "y", "$&", "abbbbc");
    test(regex_56, 56, "ab{3,4}bc", "abbbbc", "y", "$-[0]", "0");
    test(regex_57, 57, "ab{3,4}bc", "abbbbc", "y", "$+[0]", "6");
    test(regex_58, 58, "ab{4,5}bc", "abbbbc", "n", "-", "-");
    test(regex_59, 59, "ab?bc", "abbc", "y", "$&", "abbc");
    test(regex_60, 60, "ab?bc", "abc", "y", "$&", "abc");
    test(regex_61, 61, "ab{0,1}bc", "abc", "y", "$&", "abc");
    test(regex_62, 62, "ab?bc", "abbbbc", "n", "-", "-");
    test(regex_63, 63, "ab?c", "abc", "y", "$&", "abc");
    test(regex_64, 64, "ab{0,1}c", "abc", "y", "$&", "abc");
    test(regex_65, 65, "^abc\\$", "abc", "y", "$&", "abc");
    test(regex_66, 66, "^abc\\$", "abcc", "n", "-", "-");
    test(regex_67, 67, "^abc", "abcc", "y", "$&", "abc");
    test(regex_68, 68, "^abc\\$", "aabc", "n", "-", "-");
    test(regex_69, 69, "abc\\$", "aabc", "y", "$&", "abc");
    test(regex_70, 70, "abc\\$", "aabcd", "n", "-", "-");
    test(regex_71, 71, "^", "abc", "y", "$&", "");
    test(regex_72, 72, "\\$", "abc", "y", "$&", "");
    test(regex_73, 73, "a.c", "abc", "y", "$&", "abc");
    test(regex_74, 74, "a.c", "axc", "y", "$&", "axc");
    test(regex_75, 75, "a\\\\Nc", "abc", "y", "$&", "abc");
    test(regex_76, 76, "a.*c", "axyzc", "y", "$&", "axyzc");
    test(regex_77, 77, "a\\\\N*c", "axyzc", "y", "$&", "axyzc");
    test(regex_78, 78, "a.*c", "axyzd", "n", "-", "-");
    test(regex_79, 79, "a\\\\N*c", "axyzd", "n", "-", "-");
    test(regex_80, 80, "a[bc]d", "abc", "n", "-", "-");
    test(regex_81, 81, "a[bc]d", "abd", "y", "$&", "abd");
    test(regex_82, 82, "a[b]d", "abd", "y", "$&", "abd");
    test(regex_83, 83, "[a][b][d]", "abd", "y", "$&", "abd");
    test(regex_84, 84, ".[b].", "abd", "y", "$&", "abd");
    test(regex_85, 85, ".[b].", "aBd", "n", "-", "-");
    test(regex_86, 86, "a[b-d]e", "abd", "n", "-", "-");
    test(regex_87, 87, "a[b-d]e", "ace", "y", "$&", "ace");
    test(regex_88, 88, "a[b-d]", "aac", "y", "$&", "ac");
    test(regex_89, 89, "a[-b]", "a-", "y", "$&", "a-");
    test(regex_90, 90, "a[b-]", "a-", "y", "$&", "a-");
    test(regex_91, 91, "a]", "a]", "y", "$&", "a]");
    test(regex_92, 92, "a[]]b", "a]b", "y", "$&", "a]b");
    test(regex_93, 93, "a[^bc]d", "aed", "y", "$&", "aed");
    test(regex_94, 94, "a[^bc]d", "abd", "n", "-", "-");
    test(regex_95, 95, "a[^-b]c", "adc", "y", "$&", "adc");
    test(regex_96, 96, "a[^-b]c", "a-c", "n", "-", "-");
    test(regex_97, 97, "a[^]b]c", "a]c", "n", "-", "-");
    test(regex_98, 98, "a[^]b]c", "adc", "y", "$&", "adc");
    test(regex_99, 99, "\\ba\\b", "a-", "y", "-", "-");
    test(regex_100, 100, "\\ba\\b", "-a", "y", "-", "-");
    test(regex_101, 101, "\\ba\\b", "-a-", "y", "-", "-");
    test(regex_102, 102, "\\by\\b", "xy", "n", "-", "-");
    test(regex_103, 103, "\\by\\b", "yz", "n", "-", "-");
    test(regex_104, 104, "\\by\\b", "xyz", "n", "-", "-");
    test(regex_105, 105, "\\Ba\\B", "a-", "n", "-", "-");
    test(regex_106, 106, "\\Ba\\B", "-a", "n", "-", "-");
    test(regex_107, 107, "\\Ba\\B", "-a-", "n", "-", "-");
    test(regex_108, 108, "\\By\\b", "xy", "y", "-", "-");
    test(regex_109, 109, "\\By\\b", "xy", "y", "$-[0]", "1");
    test(regex_110, 110, "\\By\\b", "xy", "y", "$+[0]", "2");
    test(regex_111, 111, "\\By\\b", "xy", "y", "-", "-");
    test(regex_112, 112, "\\by\\B", "yz", "y", "-", "-");
    test(regex_113, 113, "\\By\\B", "xyz", "y", "-", "-");
    test(regex_114, 114, "\\b", "", "n", "-", "-");
    test(regex_115, 115, "\\B", "", "y", "-", "-");
    test(regex_116, 116, "\\w", "a", "y", "-", "-");
    test(regex_117, 117, "\\w", "-", "n", "-", "-");
    test(regex_118, 118, "\\W", "a", "n", "-", "-");
    test(regex_119, 119, "\\W", "-", "y", "-", "-");
    test(regex_120, 120, "a\\sb", "a b", "y", "-", "-");
    test(regex_121, 121, "a\\sb", "a-b", "n", "-", "-");
    test(regex_122, 122, "a\\Sb", "a b", "n", "-", "-");
    test(regex_123, 123, "a\\Sb", "a-b", "y", "-", "-");
    test(regex_124, 124, "\\d", "1", "y", "-", "-");
    test(regex_125, 125, "\\d", "-", "n", "-", "-");
    test(regex_126, 126, "\\D", "1", "n", "-", "-");
    test(regex_127, 127, "\\D", "-", "y", "-", "-");
    test(regex_128, 128, "[\\w]", "a", "y", "-", "-");
    test(regex_129, 129, "[\\w]", "-", "n", "-", "-");
    test(regex_130, 130, "[\\W]", "a", "n", "-", "-");
    test(regex_131, 131, "[\\W]", "-", "y", "-", "-");
    test(regex_132, 132, "a[\\s]b", "a b", "y", "-", "-");
    test(regex_133, 133, "a[\\s]b", "a-b", "n", "-", "-");
    test(regex_134, 134, "a[\\S]b", "a b", "n", "-", "-");
    test(regex_135, 135, "a[\\S]b", "a-b", "y", "-", "-");
    test(regex_136, 136, "[\\d]", "1", "y", "-", "-");
    test(regex_137, 137, "[\\d]", "-", "n", "-", "-");
    test(regex_138, 138, "[\\D]", "1", "n", "-", "-");
    test(regex_139, 139, "[\\D]", "-", "y", "-", "-");
    test(regex_140, 140, "ab|cd", "abc", "y", "$&", "ab");
    test(regex_141, 141, "ab|cd", "abcd", "y", "$&", "ab");
    test(regex_142, 142, "()ef", "def", "y", "$&-$1", "ef-");
    test(regex_143, 143, "()ef", "def", "y", "$-[0]", "1");
    test(regex_144, 144, "()ef", "def", "y", "$+[0]", "3");
    test(regex_145, 145, "()ef", "def", "y", "$-[1]", "1");
    test(regex_146, 146, "()ef", "def", "y", "$+[1]", "1");
    test(regex_147, 147, "\\$b", "b", "n", "-", "-");
    test(regex_148, 148, "a\\(b", "a(b", "y", "$&-$1", "a(b-");
    test(regex_149, 149, "a\\(*b", "ab", "y", "$&", "ab");
    test(regex_150, 150, "a\\(*b", "a((b", "y", "$&", "a((b");
    test(regex_151, 151, "a\\\\b", "a\\b", "y", "$&", "a\\b");
    test(regex_152, 152, "((a))", "abc", "y", "$&-$1-$2", "a-a-a");
    test(regex_153, 153, "((a))", "abc", "y", "$-[0]-$-[1]-$-[2]", "0-0-0");
    test(regex_154, 154, "((a))", "abc", "y", "$+[0]-$+[1]-$+[2]", "1-1-1");
    test(regex_155, 155, "(foo)(\\g-2)", "foofoo", "y", "$1-$2", "foo-foo");
    test(regex_156, 156, "(foo)(\\g-2)(foo)(\\g-2)", "foofoofoofoo", "y", "$1-$2-$3-$4", "foo-foo-foo-foo");
    test(regex_157, 157, "(([abc]+) \\g-1)(([abc]+) \\g{-1})", "abc abccba cba", "y", "$2-$4", "abc-cba");
    test(regex_158, 158, "(a)(b)(c)\\g1\\g2\\g3", "abcabc", "y", "$1$2$3", "abc");
    test(regex_159, 159, "abc", "ABC", "y", "$&", "ABC");
    test(regex_160, 160, "abc", "XBC", "n", "-", "-");
    test(regex_161, 161, "abc", "AXC", "n", "-", "-");
    test(regex_162, 162, "abc", "ABX", "n", "-", "-");
    test(regex_163, 163, "abc", "XABCY", "y", "$&", "ABC");
    test(regex_164, 164, "abc", "ABABC", "y", "$&", "ABC");
    test(regex_165, 165, "ab*c", "ABC", "y", "$&", "ABC");
    test(regex_166, 166, "ab*bc", "ABC", "y", "$&", "ABC");
    test(regex_167, 167, "ab*bc", "ABBC", "y", "$&", "ABBC");
    test(regex_168, 168, "ab*?bc", "ABBBBC", "y", "$&", "ABBBBC");
    test(regex_169, 169, "ab{0,}?bc", "ABBBBC", "y", "$&", "ABBBBC");
    test(regex_170, 170, "ab+?bc", "ABBC", "y", "$&", "ABBC");
    test(regex_171, 171, "ab+bc", "ABC", "n", "-", "-");
    test(regex_172, 172, "ab+bc", "ABQ", "n", "-", "-");
    test(regex_173, 173, "ab{1,}bc", "ABQ", "n", "-", "-");
    test(regex_174, 174, "ab+bc", "ABBBBC", "y", "$&", "ABBBBC");
    test(regex_175, 175, "ab{1,}?bc", "ABBBBC", "y", "$&", "ABBBBC");
    test(regex_176, 176, "ab{1,3}?bc", "ABBBBC", "y", "$&", "ABBBBC");
    test(regex_177, 177, "ab{3,4}?bc", "ABBBBC", "y", "$&", "ABBBBC");
    test(regex_178, 178, "ab{4,5}?bc", "ABBBBC", "n", "-", "-");
    test(regex_179, 179, "ab??bc", "ABBC", "y", "$&", "ABBC");
    test(regex_180, 180, "ab??bc", "ABC", "y", "$&", "ABC");
    test(regex_181, 181, "ab{0,1}?bc", "ABC", "y", "$&", "ABC");
    test(regex_182, 182, "ab??bc", "ABBBBC", "n", "-", "-");
    test(regex_183, 183, "ab??c", "ABC", "y", "$&", "ABC");
    test(regex_184, 184, "ab{0,1}?c", "ABC", "y", "$&", "ABC");
    test(regex_185, 185, "^abc\\$", "ABC", "y", "$&", "ABC");
    test(regex_186, 186, "^abc\\$", "ABCC", "n", "-", "-");
    test(regex_187, 187, "^abc", "ABCC", "y", "$&", "ABC");
    test(regex_188, 188, "^abc\\$", "AABC", "n", "-", "-");
    test(regex_189, 189, "abc\\$", "AABC", "y", "$&", "ABC");
    test(regex_190, 190, "^", "ABC", "y", "$&", "");
    test(regex_191, 191, "\\$", "ABC", "y", "$&", "");
    test(regex_192, 192, "a.c", "ABC", "y", "$&", "ABC");
    test(regex_193, 193, "a.c", "AXC", "y", "$&", "AXC");
    test(regex_194, 194, "a\\\\Nc", "ABC", "y", "$&", "ABC");
    test(regex_195, 195, "a.*?c", "AXYZC", "y", "$&", "AXYZC");
    test(regex_196, 196, "a.*c", "AXYZD", "n", "-", "-");
    test(regex_197, 197, "a[bc]d", "ABC", "n", "-", "-");
    test(regex_198, 198, "a[bc]d", "ABD", "y", "$&", "ABD");
    test(regex_199, 199, "a[b-d]e", "ABD", "n", "-", "-");
    test(regex_200, 200, "a[b-d]e", "ACE", "y", "$&", "ACE");
    test(regex_201, 201, "a[b-d]", "AAC", "y", "$&", "AC");
    test(regex_202, 202, "a[-b]", "A-", "y", "$&", "A-");
    test(regex_203, 203, "a[b-]", "A-", "y", "$&", "A-");
    test(regex_204, 204, "a]", "A]", "y", "$&", "A]");
    test(regex_205, 205, "a[]]b", "A]B", "y", "$&", "A]B");
    test(regex_206, 206, "a[^bc]d", "AED", "y", "$&", "AED");
    test(regex_207, 207, "a[^bc]d", "ABD", "n", "-", "-");
    test(regex_208, 208, "a[^-b]c", "ADC", "y", "$&", "ADC");
    test(regex_209, 209, "a[^-b]c", "A-C", "n", "-", "-");
    test(regex_210, 210, "a[^]b]c", "A]C", "n", "-", "-");
    test(regex_211, 211, "a[^]b]c", "ADC", "y", "$&", "ADC");
    test(regex_212, 212, "ab|cd", "ABC", "y", "$&", "AB");
    test(regex_213, 213, "ab|cd", "ABCD", "y", "$&", "AB");
    test(regex_214, 214, "()ef", "DEF", "y", "$&-$1", "EF-");
    test(regex_215, 215, "\\$b", "B", "n", "-", "-");
    test(regex_216, 216, "a\\(b", "A(B", "y", "$&-$1", "A(B-");
    test(regex_217, 217, "a\\(*b", "AB", "y", "$&", "AB");
    test(regex_218, 218, "a\\(*b", "A((B", "y", "$&", "A((B");
    test(regex_219, 219, "a\\\\b", "A\\B", "y", "$&", "A\\B");
    test(regex_220, 220, "((a))", "ABC", "y", "$&-$1-$2", "A-A-A");
    test(regex_221, 221, "(a)b(c)", "ABC", "y", "$&-$1-$2", "ABC-A-C");
    test(regex_222, 222, "a+b+c", "AABBABC", "y", "$&", "ABC");
    test(regex_223, 223, "a{1,}b{1,}c", "AABBABC", "y", "$&", "ABC");
    test(regex_224, 224, "a.+?c", "ABCABC", "y", "$&", "ABC");
    test(regex_225, 225, "a.*?c", "ABCABC", "y", "$&", "ABC");
    test(regex_226, 226, "a.{0,5}?c", "ABCABC", "y", "$&", "ABC");
    test(regex_227, 227, "(a+|b)*", "AB", "y", "$&-$1", "AB-B");
    test(regex_228, 228, "(a+|b){0,}", "AB", "y", "$&-$1", "AB-B");
    test(regex_229, 229, "(a+|b)+", "AB", "y", "$&-$1", "AB-B");
    test(regex_230, 230, "(a+|b){1,}", "AB", "y", "$&-$1", "AB-B");
    test(regex_231, 231, "(a+|b)?", "AB", "y", "$&-$1", "A-A");
    test(regex_232, 232, "(a+|b){0,1}", "AB", "y", "$&-$1", "A-A");
    test(regex_233, 233, "(a+|b){0,1}?", "AB", "y", "$&-$1", "-");
    test(regex_234, 234, "[^ab]*", "CDE", "y", "$&", "CDE");
    test(regex_235, 235, "abc", "", "n", "-", "-");
    test(regex_236, 236, "a*", "", "y", "$&", "");
    test(regex_237, 237, "([abc])*d", "ABBBCD", "y", "$&-$1", "ABBBCD-C");
    test(regex_238, 238, "([abc])*bcd", "ABCD", "y", "$&-$1", "ABCD-A");
    test(regex_239, 239, "a|b|c|d|e", "E", "y", "$&", "E");
    test(regex_240, 240, "(a|b|c|d|e)f", "EF", "y", "$&-$1", "EF-E");
    test(regex_241, 241, "abcd*efg", "ABCDEFG", "y", "$&", "ABCDEFG");
    test(regex_242, 242, "ab*", "XABYABBBZ", "y", "$&", "AB");
    test(regex_243, 243, "ab*", "XAYABBBZ", "y", "$&", "A");
    test(regex_244, 244, "(ab|cd)e", "ABCDE", "y", "$&-$1", "CDE-CD");
    test(regex_245, 245, "[abhgefdc]ij", "HIJ", "y", "$&", "HIJ");
    test(regex_246, 246, "^(ab|cd)e", "ABCDE", "n", "x$1y", "XY");
    test(regex_247, 247, "(abc|)ef", "ABCDEF", "y", "$&-$1", "EF-");
    test(regex_248, 248, "(a|b)c*d", "ABCD", "y", "$&-$1", "BCD-B");
    test(regex_249, 249, "(ab|ab*)bc", "ABC", "y", "$&-$1", "ABC-A");
    test(regex_250, 250, "a([bc]*)c*", "ABC", "y", "$&-$1", "ABC-BC");
    test(regex_251, 251, "a([bc]*)(c*d)", "ABCD", "y", "$&-$1-$2", "ABCD-BC-D");
    test(regex_252, 252, "a([bc]+)(c*d)", "ABCD", "y", "$&-$1-$2", "ABCD-BC-D");
    test(regex_253, 253, "a([bc]*)(c+d)", "ABCD", "y", "$&-$1-$2", "ABCD-B-CD");
    test(regex_254, 254, "a[bcd]*dcdcde", "ADCDCDE", "y", "$&", "ADCDCDE");
    test(regex_255, 255, "a[bcd]+dcdcde", "ADCDCDE", "n", "-", "-");
    test(regex_256, 256, "(ab|a)b*c", "ABC", "y", "$&-$1", "ABC-AB");
    test(regex_257, 257, "((a)(b)c)(d)", "ABCD", "y", "$1-$2-$3-$4", "ABC-A-B-D");
    test(regex_258, 258, "[a-zA-Z_][a-zA-Z0-9_]*", "ALPHA", "y", "$&", "ALPHA");
    test(regex_259, 259, "^a(bc+|b[eh])g|.h\\$", "ABH", "y", "$&-$1", "BH-");
    test(regex_260, 260, "(bc+d\\$|ef*g.|h?i(j|k))", "EFFGZ", "y", "$&-$1-$2", "EFFGZ-EFFGZ-");
    test(regex_261, 261, "(bc+d\\$|ef*g.|h?i(j|k))", "IJ", "y", "$&-$1-$2", "IJ-IJ-J");
    test(regex_262, 262, "(bc+d\\$|ef*g.|h?i(j|k))", "EFFG", "n", "-", "-");
    test(regex_263, 263, "(bc+d\\$|ef*g.|h?i(j|k))", "BCDD", "n", "-", "-");
    test(regex_264, 264, "(bc+d\\$|ef*g.|h?i(j|k))", "REFFGZ", "y", "$&-$1-$2", "EFFGZ-EFFGZ-");
    test(regex_265, 265, "((((((((((a))))))))))", "A", "y", "$10", "A");
    test(regex_266, 266, "((((((((((a))))))))))\\10", "AA", "y", "$&", "AA");
    test(regex_267, 267, "(((((((((a)))))))))", "A", "y", "$&", "A");
    test(regex_268, 268, "multiple words of text", "UH-UH", "n", "-", "-");
    test(regex_269, 269, "multiple words", "MULTIPLE WORDS, YEAH", "y", "$&", "MULTIPLE WORDS");
    test(regex_270, 270, "(.*)c(.*)", "ABCDE", "y", "$&-$1-$2", "ABCDE-AB-DE");
    test(regex_271, 271, "\\((.*), (.*)\\)", "(A, B)", "y", "($2, $1)", "(B, A)");
    test(regex_272, 272, "[k]", "AB", "n", "-", "-");
    test(regex_273, 273, "abcd", "ABCD", "y", "$&", "ABCD");
    test(regex_274, 274, "a(bc)d", "ABCD", "y", "$1", "BC");
    test(regex_275, 275, "a[-]?c", "AC", "y", "$&", "AC");
    test(regex_276, 276, "(abc)\\1", "ABCABC", "y", "$1", "ABC");
    test(regex_277, 277, "([a-c]*)\\1", "ABCABC", "y", "$1", "ABC");
    test(regex_278, 278, "a++a", "aaaaa", "n", "-", "-");
    test(regex_279, 279, "a*+a", "aaaaa", "n", "-", "-");
    test(regex_280, 280, "a{1,5}+a", "aaaaa", "n", "-", "-");
    test(regex_281, 281, "a?+a", "ab", "n", "-", "-");
    test(regex_282, 282, "a++b", "aaaaab", "y", "$&", "aaaaab");
    test(regex_283, 283, "a*+b", "aaaaab", "y", "$&", "aaaaab");
    test(regex_284, 284, "a{1,5}+b", "aaaaab", "y", "$&", "aaaaab");
    test(regex_285, 285, "a?+b", "ab", "y", "$&", "ab");
    test(regex_286, 286, "fooa++a", "fooaaaaa", "n", "-", "-");
    test(regex_287, 287, "fooa*+a", "fooaaaaa", "n", "-", "-");
    test(regex_288, 288, "fooa{1,5}+a", "fooaaaaa", "n", "-", "-");
    test(regex_289, 289, "fooa?+a", "fooab", "n", "-", "-");
    test(regex_290, 290, "fooa++b", "fooaaaaab", "y", "$&", "fooaaaaab");
    test(regex_291, 291, "fooa*+b", "fooaaaaab", "y", "$&", "fooaaaaab");
    test(regex_292, 292, "fooa{1,5}+b", "fooaaaaab", "y", "$&", "fooaaaaab");
    test(regex_293, 293, "fooa?+b", "fooab", "y", "$&", "fooab");
    test(regex_294, 294, "(aA)++(aA)", "aAaAaAaAaA", "n", "-", "aAaAaAaAaA");
    test(regex_295, 295, "(aA|bB)++(aA|bB)", "aAaAbBaAbB", "n", "-", "aAaAbBaAbB");
    test(regex_296, 296, "(aA)*+(aA)", "aAaAaAaAaA", "n", "-", "aAaAaAaAaA");
    test(regex_297, 297, "(aA|bB)*+(aA|bB)", "aAaAbBaAaA", "n", "-", "aAaAbBaAaA");
    test(regex_298, 298, "(aA){1,5}+(aA)", "aAaAaAaAaA", "n", "-", "aAaAaAaAaA");
    test(regex_299, 299, "(aA|bB){1,5}+(aA|bB)", "aAaAbBaAaA", "n", "-", "aAaAbBaAaA");
    test(regex_300, 300, "(aA)?+(aA)", "aAb", "n", "-", "aAb");
    test(regex_301, 301, "(aA|bB)?+(aA|bB)", "bBb", "n", "-", "bBb");
    test(regex_302, 302, "(aA)++b", "aAaAaAaAaAb", "y", "$&", "aAaAaAaAaAb");
    test(regex_303, 303, "(aA|bB)++b", "aAbBaAaAbBb", "y", "$&", "aAbBaAaAbBb");
    test(regex_304, 304, "(aA)*+b", "aAaAaAaAaAb", "y", "$&", "aAaAaAaAaAb");
    test(regex_305, 305, "(aA|bB)*+b", "bBbBbBbBbBb", "y", "$&", "bBbBbBbBbBb");
    test(regex_306, 306, "(aA){1,5}+b", "aAaAaAaAaAb", "y", "$&", "aAaAaAaAaAb");
    test(regex_307, 307, "(aA|bB){1,5}+b", "bBaAbBaAbBb", "y", "$&", "bBaAbBaAbBb");
    test(regex_308, 308, "(aA)?+b", "aAb", "y", "$&", "aAb");
    test(regex_309, 309, "(aA|bB)?+b", "bBb", "y", "$&", "bBb");
    test(regex_310, 310, "foo(aA)++(aA)", "fooaAaAaAaAaA", "n", "-", "fooaAaAaAaAaA");
    test(regex_311, 311, "foo(aA|bB)++(aA|bB)", "foobBbBbBaAaA", "n", "-", "foobBbBbBaAaA");
    test(regex_312, 312, "foo(aA)*+(aA)", "fooaAaAaAaAaA", "n", "-", "fooaAaAaAaAaA");
    test(regex_313, 313, "foo(aA|bB)*+(aA|bB)", "foobBaAbBaAaA", "n", "-", "foobBaAbBaAaA");
    test(regex_314, 314, "foo(aA){1,5}+(aA)", "fooaAaAaAaAaA", "n", "-", "fooaAaAaAaAaA");
    test(regex_315, 315, "foo(aA|bB){1,5}+(aA|bB)", "fooaAbBbBaAaA", "n", "-", "fooaAbBbBaAaA");
    test(regex_316, 316, "foo(aA)?+(aA)", "fooaAb", "n", "-", "fooaAb");
    test(regex_317, 317, "foo(aA|bB)?+(aA|bB)", "foobBb", "n", "-", "foobBb");
    test(regex_318, 318, "foo(aA)++b", "fooaAaAaAaAaAb", "y", "$&", "fooaAaAaAaAaAb");
    test(regex_319, 319, "foo(aA|bB)++b", "foobBaAbBaAbBb", "y", "$&", "foobBaAbBaAbBb");
    test(regex_320, 320, "foo(aA)*+b", "fooaAaAaAaAaAb", "y", "$&", "fooaAaAaAaAaAb");
    test(regex_321, 321, "foo(aA|bB)*+b", "foobBbBaAaAaAb", "y", "$&", "foobBbBaAaAaAb");
    test(regex_322, 322, "foo(aA){1,5}+b", "fooaAaAaAaAaAb", "y", "$&", "fooaAaAaAaAaAb");
    test(regex_323, 323, "foo(aA|bB){1,5}+b", "foobBaAaAaAaAb", "y", "$&", "foobBaAaAaAaAb");
    test(regex_324, 324, "foo(aA)?+b", "fooaAb", "y", "$&", "fooaAb");
    test(regex_325, 325, "foo(aA|bB)?+b", "foobBb", "y", "$&", "foobBb");
    test(regex_326, 326, "foo(\\h+)bar", "foo\tbar", "y", "$1", "\t");
    test(regex_327, 327, "(\\H+)(\\h)", "foo\tbar", "y", "$1-$2", "foo-\t");
    test(regex_328, 328, "(\\h+)(\\H)", "foo\tbar", "y", "$1-$2", "\t-b");
    test(regex_329, 329, "foo(\\h)bar", "foo\tbar", "y", "$1", "\t");
    test(regex_330, 330, "(\\H)(\\h)", "foo\tbar", "y", "$1-$2", "o-\t");
    test(regex_331, 331, "(\\h)(\\H)", "foo\tbar", "y", "$1-$2", "\t-b");
    test(regex_332, 332, "foo(\\v+)bar", "foo\r\n\r\n\nbar", "y", "$1", "\r\n\r\n\n");
    test(regex_333, 333, "(\\V+)(\\v)", "foo\r\n\r\n\nbar", "y", "$1-$2", "foo-\r");
    test(regex_334, 334, "(\\v+)(\\V)", "foo\r\n\r\n\nbar", "y", "$1-$2", "\r\n\r\n\n-b");
    test(regex_335, 335, "foo(\\v)bar", "foo\rbar", "y", "$1", "\r");
    test(regex_336, 336, "(\\V)(\\v)", "foo\rbar", "y", "$1-$2", "o-\r");
    test(regex_337, 337, "(\\v)(\\V)", "foo\rbar", "y", "$1-$2", "\r-b");
    test(regex_338, 338, "foo\\Kbar", "foobar", "y", "$&", "bar");
    test(regex_339, 339, "foo\\t\\n\\r\\f\\a\\ebar", "foo\t\n\r\f\a\ebar", "y", "$&", "foo\t\n\r\f\a\ebar");
    std::cout << std::endl;
  }





















































































































































































































































































































































#line 1279 "pure2-regex.cpp2"
auto main(int const argc_, char** argv_) -> int{
    auto const args = cpp2::make_args(argc_, argv_); 
#line 1280 "pure2-regex.cpp2"
    CPP2_UFCS(run)(test_perl_tests());
}


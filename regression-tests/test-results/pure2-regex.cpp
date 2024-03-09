
#define CPP2_IMPORT_STD          Yes

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "pure2-regex.cpp2"

#line 153 "pure2-regex.cpp2"
class test_perl_tests_general;
  

#line 2432 "pure2-regex.cpp2"
class test_perl_tests_lookahead;
  

//=== Cpp2 type definitions and function declarations ===========================

#line 1 "pure2-regex.cpp2"
[[nodiscard]] auto create_result(cpp2::in<std::string> resultExpr, auto const& r) -> std::string;

#line 112 "pure2-regex.cpp2"
template<typename M> auto test(M const& regex, cpp2::in<int> id, cpp2::in<std::string> regex_str, cpp2::in<std::string> str, cpp2::in<std::string> kind, cpp2::in<std::string> resultExpr, 
           cpp2::in<std::string> resultExpected) -> void;

#line 153 "pure2-regex.cpp2"
class test_perl_tests_general {

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

#line 474 "pure2-regex.cpp2"
  private: std::string var_regex_159 {"abc"}; 

#line 477 "pure2-regex.cpp2"
  private: std::string var_regex_160 {"abc"}; 

#line 480 "pure2-regex.cpp2"
  private: std::string var_regex_161 {"abc"}; 

#line 483 "pure2-regex.cpp2"
  private: std::string var_regex_162 {"abc"}; 

#line 486 "pure2-regex.cpp2"
  private: std::string var_regex_163 {"abc"}; 

#line 489 "pure2-regex.cpp2"
  private: std::string var_regex_164 {"abc"}; 

#line 492 "pure2-regex.cpp2"
  private: std::string var_regex_165 {"ab*c"}; 

#line 495 "pure2-regex.cpp2"
  private: std::string var_regex_166 {"ab*bc"}; 

#line 498 "pure2-regex.cpp2"
  private: std::string var_regex_167 {"ab*bc"}; 

#line 501 "pure2-regex.cpp2"
  private: std::string var_regex_168 {"ab*?bc"}; 

#line 504 "pure2-regex.cpp2"
  private: std::string var_regex_169 {"ab{0,}?bc"}; 

#line 507 "pure2-regex.cpp2"
  private: std::string var_regex_170 {"ab+?bc"}; 

#line 510 "pure2-regex.cpp2"
  private: std::string var_regex_171 {"ab+bc"}; 

#line 513 "pure2-regex.cpp2"
  private: std::string var_regex_172 {"ab+bc"}; 

#line 516 "pure2-regex.cpp2"
  private: std::string var_regex_173 {"ab{1,}bc"}; 

#line 519 "pure2-regex.cpp2"
  private: std::string var_regex_174 {"ab+bc"}; 

#line 522 "pure2-regex.cpp2"
  private: std::string var_regex_175 {"ab{1,}?bc"}; 

#line 525 "pure2-regex.cpp2"
  private: std::string var_regex_176 {"ab{1,3}?bc"}; 

#line 528 "pure2-regex.cpp2"
  private: std::string var_regex_177 {"ab{3,4}?bc"}; 

#line 531 "pure2-regex.cpp2"
  private: std::string var_regex_178 {"ab{4,5}?bc"}; 

#line 534 "pure2-regex.cpp2"
  private: std::string var_regex_179 {"ab??bc"}; 

#line 537 "pure2-regex.cpp2"
  private: std::string var_regex_180 {"ab??bc"}; 

#line 540 "pure2-regex.cpp2"
  private: std::string var_regex_181 {"ab{0,1}?bc"}; 

#line 543 "pure2-regex.cpp2"
  private: std::string var_regex_182 {"ab??bc"}; 

#line 546 "pure2-regex.cpp2"
  private: std::string var_regex_183 {"ab??c"}; 

#line 549 "pure2-regex.cpp2"
  private: std::string var_regex_184 {"ab{0,1}?c"}; 

#line 552 "pure2-regex.cpp2"
  private: std::string var_regex_185 {"^abc\$"}; 

#line 555 "pure2-regex.cpp2"
  private: std::string var_regex_186 {"^abc\$"}; 

#line 558 "pure2-regex.cpp2"
  private: std::string var_regex_187 {"^abc"}; 

#line 561 "pure2-regex.cpp2"
  private: std::string var_regex_188 {"^abc\$"}; 

#line 564 "pure2-regex.cpp2"
  private: std::string var_regex_189 {"abc\$"}; 

#line 567 "pure2-regex.cpp2"
  private: std::string var_regex_190 {"^"}; 

#line 570 "pure2-regex.cpp2"
  private: std::string var_regex_191 {"\$"}; 

#line 573 "pure2-regex.cpp2"
  private: std::string var_regex_192 {"a.c"}; 

#line 576 "pure2-regex.cpp2"
  private: std::string var_regex_193 {"a.c"}; 

#line 579 "pure2-regex.cpp2"
  private: std::string var_regex_194 {"a\\Nc"}; 

#line 582 "pure2-regex.cpp2"
  private: std::string var_regex_195 {"a.*?c"}; 

#line 585 "pure2-regex.cpp2"
  private: std::string var_regex_196 {"a.*c"}; 

#line 588 "pure2-regex.cpp2"
  private: std::string var_regex_197 {"a[bc]d"}; 

#line 591 "pure2-regex.cpp2"
  private: std::string var_regex_198 {"a[bc]d"}; 

#line 594 "pure2-regex.cpp2"
  private: std::string var_regex_199 {"a[b-d]e"}; 

#line 597 "pure2-regex.cpp2"
  private: std::string var_regex_200 {"a[b-d]e"}; 

#line 600 "pure2-regex.cpp2"
  private: std::string var_regex_201 {"a[b-d]"}; 

#line 603 "pure2-regex.cpp2"
  private: std::string var_regex_202 {"a[-b]"}; 

#line 606 "pure2-regex.cpp2"
  private: std::string var_regex_203 {"a[b-]"}; 

#line 609 "pure2-regex.cpp2"
  private: std::string var_regex_204 {"a]"}; 

#line 612 "pure2-regex.cpp2"
  private: std::string var_regex_205 {"a[]]b"}; 

#line 615 "pure2-regex.cpp2"
  private: std::string var_regex_206 {"a[^bc]d"}; 

#line 618 "pure2-regex.cpp2"
  private: std::string var_regex_207 {"a[^bc]d"}; 

#line 621 "pure2-regex.cpp2"
  private: std::string var_regex_208 {"a[^-b]c"}; 

#line 624 "pure2-regex.cpp2"
  private: std::string var_regex_209 {"a[^-b]c"}; 

#line 627 "pure2-regex.cpp2"
  private: std::string var_regex_210 {"a[^]b]c"}; 

#line 630 "pure2-regex.cpp2"
  private: std::string var_regex_211 {"a[^]b]c"}; 

#line 633 "pure2-regex.cpp2"
  private: std::string var_regex_212 {"ab|cd"}; 

#line 636 "pure2-regex.cpp2"
  private: std::string var_regex_213 {"ab|cd"}; 

#line 639 "pure2-regex.cpp2"
  private: std::string var_regex_214 {"()ef"}; 

#line 642 "pure2-regex.cpp2"
  private: std::string var_regex_215 {"\$b"}; 

#line 645 "pure2-regex.cpp2"
  private: std::string var_regex_216 {"a\(b"}; 

#line 648 "pure2-regex.cpp2"
  private: std::string var_regex_217 {"a\(*b"}; 

#line 651 "pure2-regex.cpp2"
  private: std::string var_regex_218 {"a\(*b"}; 

#line 654 "pure2-regex.cpp2"
  private: std::string var_regex_219 {"a\\b"}; 

#line 657 "pure2-regex.cpp2"
  private: std::string var_regex_220 {"((a))"}; 

#line 660 "pure2-regex.cpp2"
  private: std::string var_regex_221 {"(a)b(c)"}; 

#line 663 "pure2-regex.cpp2"
  private: std::string var_regex_222 {"a+b+c"}; 

#line 666 "pure2-regex.cpp2"
  private: std::string var_regex_223 {"a{1,}b{1,}c"}; 

#line 669 "pure2-regex.cpp2"
  private: std::string var_regex_224 {"a.+?c"}; 

#line 672 "pure2-regex.cpp2"
  private: std::string var_regex_225 {"a.*?c"}; 

#line 675 "pure2-regex.cpp2"
  private: std::string var_regex_226 {"a.{0,5}?c"}; 

#line 678 "pure2-regex.cpp2"
  private: std::string var_regex_227 {"(a+|b)*"}; 

#line 681 "pure2-regex.cpp2"
  private: std::string var_regex_228 {"(a+|b){0,}"}; 

#line 684 "pure2-regex.cpp2"
  private: std::string var_regex_229 {"(a+|b)+"}; 

#line 687 "pure2-regex.cpp2"
  private: std::string var_regex_230 {"(a+|b){1,}"}; 

#line 690 "pure2-regex.cpp2"
  private: std::string var_regex_231 {"(a+|b)?"}; 

#line 693 "pure2-regex.cpp2"
  private: std::string var_regex_232 {"(a+|b){0,1}"}; 

#line 696 "pure2-regex.cpp2"
  private: std::string var_regex_233 {"(a+|b){0,1}?"}; 

#line 699 "pure2-regex.cpp2"
  private: std::string var_regex_234 {"[^ab]*"}; 

#line 702 "pure2-regex.cpp2"
  private: std::string var_regex_235 {"abc"}; 

#line 705 "pure2-regex.cpp2"
  private: std::string var_regex_236 {"a*"}; 

#line 708 "pure2-regex.cpp2"
  private: std::string var_regex_237 {"([abc])*d"}; 

#line 711 "pure2-regex.cpp2"
  private: std::string var_regex_238 {"([abc])*bcd"}; 

#line 714 "pure2-regex.cpp2"
  private: std::string var_regex_239 {"a|b|c|d|e"}; 

#line 717 "pure2-regex.cpp2"
  private: std::string var_regex_240 {"(a|b|c|d|e)f"}; 

#line 720 "pure2-regex.cpp2"
  private: std::string var_regex_241 {"abcd*efg"}; 

#line 723 "pure2-regex.cpp2"
  private: std::string var_regex_242 {"ab*"}; 

#line 726 "pure2-regex.cpp2"
  private: std::string var_regex_243 {"ab*"}; 

#line 729 "pure2-regex.cpp2"
  private: std::string var_regex_244 {"(ab|cd)e"}; 

#line 732 "pure2-regex.cpp2"
  private: std::string var_regex_245 {"[abhgefdc]ij"}; 

#line 735 "pure2-regex.cpp2"
  private: std::string var_regex_246 {"^(ab|cd)e"}; 

#line 738 "pure2-regex.cpp2"
  private: std::string var_regex_247 {"(abc|)ef"}; 

#line 741 "pure2-regex.cpp2"
  private: std::string var_regex_248 {"(a|b)c*d"}; 

#line 744 "pure2-regex.cpp2"
  private: std::string var_regex_249 {"(ab|ab*)bc"}; 

#line 747 "pure2-regex.cpp2"
  private: std::string var_regex_250 {"a([bc]*)c*"}; 

#line 750 "pure2-regex.cpp2"
  private: std::string var_regex_251 {"a([bc]*)(c*d)"}; 

#line 753 "pure2-regex.cpp2"
  private: std::string var_regex_252 {"a([bc]+)(c*d)"}; 

#line 756 "pure2-regex.cpp2"
  private: std::string var_regex_253 {"a([bc]*)(c+d)"}; 

#line 759 "pure2-regex.cpp2"
  private: std::string var_regex_254 {"a[bcd]*dcdcde"}; 

#line 762 "pure2-regex.cpp2"
  private: std::string var_regex_255 {"a[bcd]+dcdcde"}; 

#line 765 "pure2-regex.cpp2"
  private: std::string var_regex_256 {"(ab|a)b*c"}; 

#line 768 "pure2-regex.cpp2"
  private: std::string var_regex_257 {"((a)(b)c)(d)"}; 

#line 771 "pure2-regex.cpp2"
  private: std::string var_regex_258 {"[a-zA-Z_][a-zA-Z0-9_]*"}; 

#line 774 "pure2-regex.cpp2"
  private: std::string var_regex_259 {"^a(bc+|b[eh])g|.h\$"}; 

#line 777 "pure2-regex.cpp2"
  private: std::string var_regex_260 {"(bc+d\$|ef*g.|h?i(j|k))"}; 

#line 780 "pure2-regex.cpp2"
  private: std::string var_regex_261 {"(bc+d\$|ef*g.|h?i(j|k))"}; 

#line 783 "pure2-regex.cpp2"
  private: std::string var_regex_262 {"(bc+d\$|ef*g.|h?i(j|k))"}; 

#line 786 "pure2-regex.cpp2"
  private: std::string var_regex_263 {"(bc+d\$|ef*g.|h?i(j|k))"}; 

#line 789 "pure2-regex.cpp2"
  private: std::string var_regex_264 {"(bc+d\$|ef*g.|h?i(j|k))"}; 

#line 792 "pure2-regex.cpp2"
  private: std::string var_regex_265 {"((((((((((a))))))))))"}; 

#line 795 "pure2-regex.cpp2"
  private: std::string var_regex_266 {"((((((((((a))))))))))\10"}; 

#line 798 "pure2-regex.cpp2"
  private: std::string var_regex_267 {"(((((((((a)))))))))"}; 

#line 801 "pure2-regex.cpp2"
  private: std::string var_regex_268 {"multiple words of text"}; 

#line 804 "pure2-regex.cpp2"
  private: std::string var_regex_269 {"multiple words"}; 

#line 807 "pure2-regex.cpp2"
  private: std::string var_regex_270 {"(.*)c(.*)"}; 

#line 810 "pure2-regex.cpp2"
  private: std::string var_regex_271 {"\((.*), (.*)\)"}; 

#line 813 "pure2-regex.cpp2"
  private: std::string var_regex_272 {"[k]"}; 

#line 816 "pure2-regex.cpp2"
  private: std::string var_regex_273 {"abcd"}; 

#line 819 "pure2-regex.cpp2"
  private: std::string var_regex_274 {"a(bc)d"}; 

#line 822 "pure2-regex.cpp2"
  private: std::string var_regex_275 {"a[-]?c"}; 

#line 825 "pure2-regex.cpp2"
  private: std::string var_regex_276 {"(abc)\1"}; 

#line 828 "pure2-regex.cpp2"
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

  private: std::string var_regex_338 {"(?:(?i)a)b"}; 

  private: std::string var_regex_339 {"((?i)a)b"}; 

  private: std::string var_regex_340 {"(?:(?i)a)b"}; 

  private: std::string var_regex_341 {"((?i)a)b"}; 

  private: std::string var_regex_342 {"(?:(?i)a)b"}; 

  private: std::string var_regex_343 {"((?i)a)b"}; 

  private: std::string var_regex_344 {"(?i:a)b"}; 

  private: std::string var_regex_345 {"((?i:a))b"}; 

  private: std::string var_regex_346 {"(?i:a)b"}; 

  private: std::string var_regex_347 {"((?i:a))b"}; 

  private: std::string var_regex_348 {"(?i:a)b"}; 

  private: std::string var_regex_349 {"((?i:a))b"}; 

#line 975 "pure2-regex.cpp2"
  private: std::string var_regex_350 {"(?:(?-i)a)b"}; 

#line 978 "pure2-regex.cpp2"
  private: std::string var_regex_351 {"((?-i)a)b"}; 

#line 981 "pure2-regex.cpp2"
  private: std::string var_regex_352 {"(?:(?-i)a)b"}; 

#line 984 "pure2-regex.cpp2"
  private: std::string var_regex_353 {"((?-i)a)b"}; 

#line 987 "pure2-regex.cpp2"
  private: std::string var_regex_354 {"(?:(?-i)a)b"}; 

#line 990 "pure2-regex.cpp2"
  private: std::string var_regex_355 {"((?-i)a)b"}; 

#line 993 "pure2-regex.cpp2"
  private: std::string var_regex_356 {"(?:(?-i)a)b"}; 

#line 996 "pure2-regex.cpp2"
  private: std::string var_regex_357 {"((?-i)a)b"}; 

#line 999 "pure2-regex.cpp2"
  private: std::string var_regex_358 {"(?:(?-i)a)b"}; 

#line 1002 "pure2-regex.cpp2"
  private: std::string var_regex_359 {"((?-i)a)b"}; 

#line 1005 "pure2-regex.cpp2"
  private: std::string var_regex_360 {"(?-i:a)b"}; 

#line 1008 "pure2-regex.cpp2"
  private: std::string var_regex_361 {"((?-i:a))b"}; 

#line 1011 "pure2-regex.cpp2"
  private: std::string var_regex_362 {"(?-i:a)b"}; 

#line 1014 "pure2-regex.cpp2"
  private: std::string var_regex_363 {"((?-i:a))b"}; 

#line 1017 "pure2-regex.cpp2"
  private: std::string var_regex_364 {"(?-i:a)b"}; 

#line 1020 "pure2-regex.cpp2"
  private: std::string var_regex_365 {"((?-i:a))b"}; 

#line 1023 "pure2-regex.cpp2"
  private: std::string var_regex_366 {"(?-i:a)b"}; 

#line 1026 "pure2-regex.cpp2"
  private: std::string var_regex_367 {"((?-i:a))b"}; 

#line 1029 "pure2-regex.cpp2"
  private: std::string var_regex_368 {"(?-i:a)b"}; 

#line 1032 "pure2-regex.cpp2"
  private: std::string var_regex_369 {"((?-i:a))b"}; 

#line 1035 "pure2-regex.cpp2"
  private: std::string var_regex_370 {"((?-i:a.))b"}; 

#line 1038 "pure2-regex.cpp2"
  private: std::string var_regex_371 {"((?-i:a\\N))b"}; 

#line 1041 "pure2-regex.cpp2"
  private: std::string var_regex_372 {"((?s-i:a.))b"}; 

#line 1044 "pure2-regex.cpp2"
  private: std::string var_regex_373 {"((?s-i:a\\N))b"}; 

#line 1047 "pure2-regex.cpp2"
  private: std::string var_regex_374 {"((?s-i:a.))b"}; 

#line 1050 "pure2-regex.cpp2"
  private: std::string var_regex_375 {"((?s-i:a\\N))b"}; 

  private: std::string var_regex_376 {"^(?:a?b?)*\$"}; 

  private: std::string var_regex_377 {"((?s)^a(.))((?m)^b\$)"}; 

  private: std::string var_regex_378 {"((?m)^b\$)"}; 

  private: std::string var_regex_379 {"(?m)^b"}; 

  private: std::string var_regex_380 {"(?m)^(b)"}; 

  private: std::string var_regex_381 {"((?m)^b)"}; 

  private: std::string var_regex_382 {"\n((?m)^b)"}; 

  private: std::string var_regex_383 {"^b"}; 

  private: std::string var_regex_384 {"()^b"}; 

  private: std::string var_regex_385 {"((?m)^b)"}; 

  private: std::string var_regex_386 {"\Z"}; 

  private: std::string var_regex_387 {"\z"}; 

  private: std::string var_regex_388 {"\$"}; 

  private: std::string var_regex_389 {"\Z"}; 

  private: std::string var_regex_390 {"\z"}; 

  private: std::string var_regex_391 {"\$"}; 

  private: std::string var_regex_392 {"\Z"}; 

  private: std::string var_regex_393 {"\z"}; 

  private: std::string var_regex_394 {"\$"}; 

#line 1091 "pure2-regex.cpp2"
  private: std::string var_regex_395 {"\Z"}; 

#line 1094 "pure2-regex.cpp2"
  private: std::string var_regex_396 {"\z"}; 

#line 1097 "pure2-regex.cpp2"
  private: std::string var_regex_397 {"\$"}; 

#line 1100 "pure2-regex.cpp2"
  private: std::string var_regex_398 {"\Z"}; 

#line 1103 "pure2-regex.cpp2"
  private: std::string var_regex_399 {"\z"}; 

#line 1106 "pure2-regex.cpp2"
  private: std::string var_regex_400 {"\$"}; 

#line 1109 "pure2-regex.cpp2"
  private: std::string var_regex_401 {"\Z"}; 

#line 1112 "pure2-regex.cpp2"
  private: std::string var_regex_402 {"\z"}; 

#line 1115 "pure2-regex.cpp2"
  private: std::string var_regex_403 {"\$"}; 

  private: std::string var_regex_404 {"a\Z"}; 

  private: std::string var_regex_405 {"a\z"}; 

  private: std::string var_regex_406 {"a\$"}; 

  private: std::string var_regex_407 {"a\Z"}; 

  private: std::string var_regex_408 {"a\z"}; 

  private: std::string var_regex_409 {"a\$"}; 

  private: std::string var_regex_410 {"a\Z"}; 

  private: std::string var_regex_411 {"a\z"}; 

  private: std::string var_regex_412 {"a\$"}; 

#line 1136 "pure2-regex.cpp2"
  private: std::string var_regex_413 {"a\Z"}; 

#line 1139 "pure2-regex.cpp2"
  private: std::string var_regex_414 {"a\z"}; 

#line 1142 "pure2-regex.cpp2"
  private: std::string var_regex_415 {"a\$"}; 

#line 1145 "pure2-regex.cpp2"
  private: std::string var_regex_416 {"a\Z"}; 

#line 1148 "pure2-regex.cpp2"
  private: std::string var_regex_417 {"a\z"}; 

#line 1151 "pure2-regex.cpp2"
  private: std::string var_regex_418 {"a\$"}; 

#line 1154 "pure2-regex.cpp2"
  private: std::string var_regex_419 {"a\Z"}; 

#line 1157 "pure2-regex.cpp2"
  private: std::string var_regex_420 {"a\z"}; 

#line 1160 "pure2-regex.cpp2"
  private: std::string var_regex_421 {"a\$"}; 

  private: std::string var_regex_422 {"aa\Z"}; 

  private: std::string var_regex_423 {"aa\z"}; 

  private: std::string var_regex_424 {"aa\$"}; 

  private: std::string var_regex_425 {"aa\Z"}; 

  private: std::string var_regex_426 {"aa\z"}; 

  private: std::string var_regex_427 {"aa\$"}; 

  private: std::string var_regex_428 {"aa\Z"}; 

  private: std::string var_regex_429 {"aa\z"}; 

  private: std::string var_regex_430 {"aa\$"}; 

#line 1181 "pure2-regex.cpp2"
  private: std::string var_regex_431 {"aa\Z"}; 

#line 1184 "pure2-regex.cpp2"
  private: std::string var_regex_432 {"aa\z"}; 

#line 1187 "pure2-regex.cpp2"
  private: std::string var_regex_433 {"aa\$"}; 

#line 1190 "pure2-regex.cpp2"
  private: std::string var_regex_434 {"aa\Z"}; 

#line 1193 "pure2-regex.cpp2"
  private: std::string var_regex_435 {"aa\z"}; 

#line 1196 "pure2-regex.cpp2"
  private: std::string var_regex_436 {"aa\$"}; 

#line 1199 "pure2-regex.cpp2"
  private: std::string var_regex_437 {"aa\Z"}; 

#line 1202 "pure2-regex.cpp2"
  private: std::string var_regex_438 {"aa\z"}; 

#line 1205 "pure2-regex.cpp2"
  private: std::string var_regex_439 {"aa\$"}; 

  private: std::string var_regex_440 {"aa\Z"}; 

  private: std::string var_regex_441 {"aa\z"}; 

  private: std::string var_regex_442 {"aa\$"}; 

  private: std::string var_regex_443 {"aa\Z"}; 

  private: std::string var_regex_444 {"aa\z"}; 

  private: std::string var_regex_445 {"aa\$"}; 

  private: std::string var_regex_446 {"aa\Z"}; 

  private: std::string var_regex_447 {"aa\z"}; 

  private: std::string var_regex_448 {"aa\$"}; 

#line 1226 "pure2-regex.cpp2"
  private: std::string var_regex_449 {"aa\Z"}; 

#line 1229 "pure2-regex.cpp2"
  private: std::string var_regex_450 {"aa\z"}; 

#line 1232 "pure2-regex.cpp2"
  private: std::string var_regex_451 {"aa\$"}; 

#line 1235 "pure2-regex.cpp2"
  private: std::string var_regex_452 {"aa\Z"}; 

#line 1238 "pure2-regex.cpp2"
  private: std::string var_regex_453 {"aa\z"}; 

#line 1241 "pure2-regex.cpp2"
  private: std::string var_regex_454 {"aa\$"}; 

#line 1244 "pure2-regex.cpp2"
  private: std::string var_regex_455 {"aa\Z"}; 

#line 1247 "pure2-regex.cpp2"
  private: std::string var_regex_456 {"aa\z"}; 

#line 1250 "pure2-regex.cpp2"
  private: std::string var_regex_457 {"aa\$"}; 

  private: std::string var_regex_458 {"aa\Z"}; 

  private: std::string var_regex_459 {"aa\z"}; 

  private: std::string var_regex_460 {"aa\$"}; 

  private: std::string var_regex_461 {"aa\Z"}; 

  private: std::string var_regex_462 {"aa\z"}; 

  private: std::string var_regex_463 {"aa\$"}; 

  private: std::string var_regex_464 {"aa\Z"}; 

  private: std::string var_regex_465 {"aa\z"}; 

  private: std::string var_regex_466 {"aa\$"}; 

#line 1271 "pure2-regex.cpp2"
  private: std::string var_regex_467 {"aa\Z"}; 

#line 1274 "pure2-regex.cpp2"
  private: std::string var_regex_468 {"aa\z"}; 

#line 1277 "pure2-regex.cpp2"
  private: std::string var_regex_469 {"aa\$"}; 

#line 1280 "pure2-regex.cpp2"
  private: std::string var_regex_470 {"aa\Z"}; 

#line 1283 "pure2-regex.cpp2"
  private: std::string var_regex_471 {"aa\z"}; 

#line 1286 "pure2-regex.cpp2"
  private: std::string var_regex_472 {"aa\$"}; 

#line 1289 "pure2-regex.cpp2"
  private: std::string var_regex_473 {"aa\Z"}; 

#line 1292 "pure2-regex.cpp2"
  private: std::string var_regex_474 {"aa\z"}; 

#line 1295 "pure2-regex.cpp2"
  private: std::string var_regex_475 {"aa\$"}; 

  private: std::string var_regex_476 {"ab\Z"}; 

  private: std::string var_regex_477 {"ab\z"}; 

  private: std::string var_regex_478 {"ab\$"}; 

  private: std::string var_regex_479 {"ab\Z"}; 

  private: std::string var_regex_480 {"ab\z"}; 

  private: std::string var_regex_481 {"ab\$"}; 

  private: std::string var_regex_482 {"ab\Z"}; 

  private: std::string var_regex_483 {"ab\z"}; 

  private: std::string var_regex_484 {"ab\$"}; 

#line 1316 "pure2-regex.cpp2"
  private: std::string var_regex_485 {"ab\Z"}; 

#line 1319 "pure2-regex.cpp2"
  private: std::string var_regex_486 {"ab\z"}; 

#line 1322 "pure2-regex.cpp2"
  private: std::string var_regex_487 {"ab\$"}; 

#line 1325 "pure2-regex.cpp2"
  private: std::string var_regex_488 {"ab\Z"}; 

#line 1328 "pure2-regex.cpp2"
  private: std::string var_regex_489 {"ab\z"}; 

#line 1331 "pure2-regex.cpp2"
  private: std::string var_regex_490 {"ab\$"}; 

#line 1334 "pure2-regex.cpp2"
  private: std::string var_regex_491 {"ab\Z"}; 

#line 1337 "pure2-regex.cpp2"
  private: std::string var_regex_492 {"ab\z"}; 

#line 1340 "pure2-regex.cpp2"
  private: std::string var_regex_493 {"ab\$"}; 

  private: std::string var_regex_494 {"ab\Z"}; 

  private: std::string var_regex_495 {"ab\z"}; 

  private: std::string var_regex_496 {"ab\$"}; 

  private: std::string var_regex_497 {"ab\Z"}; 

  private: std::string var_regex_498 {"ab\z"}; 

  private: std::string var_regex_499 {"ab\$"}; 

  private: std::string var_regex_500 {"ab\Z"}; 

  private: std::string var_regex_501 {"ab\z"}; 

  private: std::string var_regex_502 {"ab\$"}; 

#line 1361 "pure2-regex.cpp2"
  private: std::string var_regex_503 {"ab\Z"}; 

#line 1364 "pure2-regex.cpp2"
  private: std::string var_regex_504 {"ab\z"}; 

#line 1367 "pure2-regex.cpp2"
  private: std::string var_regex_505 {"ab\$"}; 

#line 1370 "pure2-regex.cpp2"
  private: std::string var_regex_506 {"ab\Z"}; 

#line 1373 "pure2-regex.cpp2"
  private: std::string var_regex_507 {"ab\z"}; 

#line 1376 "pure2-regex.cpp2"
  private: std::string var_regex_508 {"ab\$"}; 

#line 1379 "pure2-regex.cpp2"
  private: std::string var_regex_509 {"ab\Z"}; 

#line 1382 "pure2-regex.cpp2"
  private: std::string var_regex_510 {"ab\z"}; 

#line 1385 "pure2-regex.cpp2"
  private: std::string var_regex_511 {"ab\$"}; 

  private: std::string var_regex_512 {"ab\Z"}; 

  private: std::string var_regex_513 {"ab\z"}; 

  private: std::string var_regex_514 {"ab\$"}; 

  private: std::string var_regex_515 {"ab\Z"}; 

  private: std::string var_regex_516 {"ab\z"}; 

  private: std::string var_regex_517 {"ab\$"}; 

  private: std::string var_regex_518 {"ab\Z"}; 

  private: std::string var_regex_519 {"ab\z"}; 

  private: std::string var_regex_520 {"ab\$"}; 

#line 1406 "pure2-regex.cpp2"
  private: std::string var_regex_521 {"ab\Z"}; 

#line 1409 "pure2-regex.cpp2"
  private: std::string var_regex_522 {"ab\z"}; 

#line 1412 "pure2-regex.cpp2"
  private: std::string var_regex_523 {"ab\$"}; 

#line 1415 "pure2-regex.cpp2"
  private: std::string var_regex_524 {"ab\Z"}; 

#line 1418 "pure2-regex.cpp2"
  private: std::string var_regex_525 {"ab\z"}; 

#line 1421 "pure2-regex.cpp2"
  private: std::string var_regex_526 {"ab\$"}; 

#line 1424 "pure2-regex.cpp2"
  private: std::string var_regex_527 {"ab\Z"}; 

#line 1427 "pure2-regex.cpp2"
  private: std::string var_regex_528 {"ab\z"}; 

#line 1430 "pure2-regex.cpp2"
  private: std::string var_regex_529 {"ab\$"}; 

  private: std::string var_regex_530 {"abb\Z"}; 

  private: std::string var_regex_531 {"abb\z"}; 

  private: std::string var_regex_532 {"abb\$"}; 

  private: std::string var_regex_533 {"abb\Z"}; 

  private: std::string var_regex_534 {"abb\z"}; 

  private: std::string var_regex_535 {"abb\$"}; 

  private: std::string var_regex_536 {"abb\Z"}; 

  private: std::string var_regex_537 {"abb\z"}; 

  private: std::string var_regex_538 {"abb\$"}; 

#line 1451 "pure2-regex.cpp2"
  private: std::string var_regex_539 {"abb\Z"}; 

#line 1454 "pure2-regex.cpp2"
  private: std::string var_regex_540 {"abb\z"}; 

#line 1457 "pure2-regex.cpp2"
  private: std::string var_regex_541 {"abb\$"}; 

#line 1460 "pure2-regex.cpp2"
  private: std::string var_regex_542 {"abb\Z"}; 

#line 1463 "pure2-regex.cpp2"
  private: std::string var_regex_543 {"abb\z"}; 

#line 1466 "pure2-regex.cpp2"
  private: std::string var_regex_544 {"abb\$"}; 

#line 1469 "pure2-regex.cpp2"
  private: std::string var_regex_545 {"abb\Z"}; 

#line 1472 "pure2-regex.cpp2"
  private: std::string var_regex_546 {"abb\z"}; 

#line 1475 "pure2-regex.cpp2"
  private: std::string var_regex_547 {"abb\$"}; 

  private: std::string var_regex_548 {"abb\Z"}; 

  private: std::string var_regex_549 {"abb\z"}; 

  private: std::string var_regex_550 {"abb\$"}; 

  private: std::string var_regex_551 {"abb\Z"}; 

  private: std::string var_regex_552 {"abb\z"}; 

  private: std::string var_regex_553 {"abb\$"}; 

  private: std::string var_regex_554 {"abb\Z"}; 

  private: std::string var_regex_555 {"abb\z"}; 

  private: std::string var_regex_556 {"abb\$"}; 

#line 1496 "pure2-regex.cpp2"
  private: std::string var_regex_557 {"abb\Z"}; 

#line 1499 "pure2-regex.cpp2"
  private: std::string var_regex_558 {"abb\z"}; 

#line 1502 "pure2-regex.cpp2"
  private: std::string var_regex_559 {"abb\$"}; 

#line 1505 "pure2-regex.cpp2"
  private: std::string var_regex_560 {"abb\Z"}; 

#line 1508 "pure2-regex.cpp2"
  private: std::string var_regex_561 {"abb\z"}; 

#line 1511 "pure2-regex.cpp2"
  private: std::string var_regex_562 {"abb\$"}; 

#line 1514 "pure2-regex.cpp2"
  private: std::string var_regex_563 {"abb\Z"}; 

#line 1517 "pure2-regex.cpp2"
  private: std::string var_regex_564 {"abb\z"}; 

#line 1520 "pure2-regex.cpp2"
  private: std::string var_regex_565 {"abb\$"}; 

  private: std::string var_regex_566 {"abb\Z"}; 

  private: std::string var_regex_567 {"abb\z"}; 

  private: std::string var_regex_568 {"abb\$"}; 

  private: std::string var_regex_569 {"abb\Z"}; 

  private: std::string var_regex_570 {"abb\z"}; 

  private: std::string var_regex_571 {"abb\$"}; 

  private: std::string var_regex_572 {"abb\Z"}; 

  private: std::string var_regex_573 {"abb\z"}; 

  private: std::string var_regex_574 {"abb\$"}; 

#line 1541 "pure2-regex.cpp2"
  private: std::string var_regex_575 {"abb\Z"}; 

#line 1544 "pure2-regex.cpp2"
  private: std::string var_regex_576 {"abb\z"}; 

#line 1547 "pure2-regex.cpp2"
  private: std::string var_regex_577 {"abb\$"}; 

#line 1550 "pure2-regex.cpp2"
  private: std::string var_regex_578 {"abb\Z"}; 

#line 1553 "pure2-regex.cpp2"
  private: std::string var_regex_579 {"abb\z"}; 

#line 1556 "pure2-regex.cpp2"
  private: std::string var_regex_580 {"abb\$"}; 

#line 1559 "pure2-regex.cpp2"
  private: std::string var_regex_581 {"abb\Z"}; 

#line 1562 "pure2-regex.cpp2"
  private: std::string var_regex_582 {"abb\z"}; 

#line 1565 "pure2-regex.cpp2"
  private: std::string var_regex_583 {"abb\$"}; 

#line 1568 "pure2-regex.cpp2"
  private: std::string var_regex_584 {"\Aa\$"}; 

  private: std::string var_regex_585 {"(?i:.[b].)"}; 

  private: std::string var_regex_586 {"(?i:\\N[b]\\N)"}; 

#line 1575 "pure2-regex.cpp2"
  private: std::string var_regex_587 {"\\N {1}"}; 

#line 1578 "pure2-regex.cpp2"
  private: std::string var_regex_588 {"\\N {1}"}; 

#line 1581 "pure2-regex.cpp2"
  private: std::string var_regex_589 {"\\N {1}"}; 

#line 1584 "pure2-regex.cpp2"
  private: std::string var_regex_590 {"\\N {3,4}"}; 

#line 1587 "pure2-regex.cpp2"
  private: std::string var_regex_591 {"\\N {3,4}"}; 

#line 1590 "pure2-regex.cpp2"
  private: std::string var_regex_592 {"\\N {3,4}"}; 

#line 1593 "pure2-regex.cpp2"
  private: std::string var_regex_593 {"a\\N c"}; 

#line 1596 "pure2-regex.cpp2"
  private: std::string var_regex_594 {"a\\N *c"}; 

#line 1599 "pure2-regex.cpp2"
  private: std::string var_regex_595 {"a\\N *c"}; 

#line 1602 "pure2-regex.cpp2"
  private: std::string var_regex_596 {"[a b]"}; 

#line 1605 "pure2-regex.cpp2"
  private: std::string var_regex_597 {"[a b]"}; 

#line 1608 "pure2-regex.cpp2"
  private: std::string var_regex_598 {"[a\ b]"}; 

#line 1611 "pure2-regex.cpp2"
  private: std::string var_regex_599 {"[ ^ a b ]"}; 

#line 1614 "pure2-regex.cpp2"
  private: std::string var_regex_600 {"[ ^ a b ]"}; 

#line 1617 "pure2-regex.cpp2"
  private: std::string var_regex_601 {"[ ^ a b ]"}; 

#line 1620 "pure2-regex.cpp2"
  private: std::string var_regex_602 {"(?x:[a b])"}; 

#line 1623 "pure2-regex.cpp2"
  private: std::string var_regex_603 {"(?xx:[a b])"}; 

#line 1626 "pure2-regex.cpp2"
  private: std::string var_regex_604 {"(?x)[a b]"}; 

#line 1629 "pure2-regex.cpp2"
  private: std::string var_regex_605 {"(?xx)[a b]"}; 

#line 1632 "pure2-regex.cpp2"
  private: std::string var_regex_606 {"(?-x:[a b])"}; 

#line 1635 "pure2-regex.cpp2"
  private: std::string var_regex_607 {"\\N {1}"}; 

#line 1638 "pure2-regex.cpp2"
  private: std::string var_regex_608 {"\\N {1}"}; 

#line 1641 "pure2-regex.cpp2"
  private: std::string var_regex_609 {"\\N {1}"}; 

#line 1644 "pure2-regex.cpp2"
  private: std::string var_regex_610 {"\\N {3,4}"}; 

#line 1647 "pure2-regex.cpp2"
  private: std::string var_regex_611 {"\\N {3,4}"}; 

#line 1650 "pure2-regex.cpp2"
  private: std::string var_regex_612 {"\\N {3,4}"}; 

#line 1653 "pure2-regex.cpp2"
  private: std::string var_regex_613 {"a\\N c"}; 

#line 1656 "pure2-regex.cpp2"
  private: std::string var_regex_614 {"a\\N *c"}; 

#line 1659 "pure2-regex.cpp2"
  private: std::string var_regex_615 {"a\\N *c"}; 

  private: std::string var_regex_616 {"[#]"}; 

  private: std::string var_regex_617 {"[#]b"}; 

#line 1666 "pure2-regex.cpp2"
  private: std::string var_regex_618 {"[#]"}; 

#line 1669 "pure2-regex.cpp2"
  private: std::string var_regex_619 {"[#]b"}; 

  private: std::string var_regex_620 {"(?'n'foo) \g{n}"}; 

  private: std::string var_regex_621 {"(?'n'foo) \g{ n }"}; 

  private: std::string var_regex_622 {"(?'n'foo) \g{n}"}; 

  private: std::string var_regex_623 {"(?<n>foo) \g{n}"}; 

  private: std::string var_regex_624 {"(?<n>foo) \g{n}"}; 

  private: std::string var_regex_625 {"(?<as>as) (\w+) \g{as} (\w+)"}; 

  private: std::string var_regex_626 {"(?'n'foo) \k<n>"}; 

  private: std::string var_regex_627 {"(?'n'foo) \k<n>"}; 

  private: std::string var_regex_628 {"(?<n>foo) \k'n'"}; 

  private: std::string var_regex_629 {"(?<n>foo) \k'n'"}; 

  private: std::string var_regex_630 {"(?'a1'foo) \k'a1'"}; 

  private: std::string var_regex_631 {"(?<a1>foo) \k<a1>"}; 

  private: std::string var_regex_632 {"(?'_'foo) \k'_'"}; 

  private: std::string var_regex_633 {"(?<_>foo) \k<_>"}; 

  private: std::string var_regex_634 {"(?'_0_'foo) \k'_0_'"}; 

  private: std::string var_regex_635 {"(?<_0_>foo) \k<_0_>"}; 

  private: std::string var_regex_636 {"(?<as>as) (\w+) \k<as> (\w+)"}; 

  private: std::string var_regex_637 {"(?<as>as) (\w+) \k{as} (\w+)"}; 

  private: std::string var_regex_638 {"(?<as>as) (\w+) \k'as' (\w+)"}; 

  private: std::string var_regex_639 {"(?<as>as) (\w+) \k{ as } (\w+)"}; 

  private: std::string var_regex_640 {"^a(?#xxx){3}c"}; 

#line 1714 "pure2-regex.cpp2"
  private: std::string var_regex_641 {"^a (?#xxx) (?#yyy) {3}c"}; 

  private: std::string var_regex_642 {"(?|(a))"}; 

  private: std::string var_regex_643 {"(?|a(.)b|d(.(o).)d|i(.)(.)j)(.)"}; 

  private: std::string var_regex_644 {"(?|a(.)b|d(.(o).)d|i(.)(.)j)(.)"}; 

  private: std::string var_regex_645 {"(?|a(.)b|d(.(o).)d|i(.)(.)j)(.)"}; 

  private: std::string var_regex_646 {"(?|(?|(a)|(b))|(?|(c)|(d)))"}; 

  private: std::string var_regex_647 {"(?|(?|(a)|(b))|(?|(c)|(d)))"}; 

  private: std::string var_regex_648 {"(?|(?|(a)|(b))|(?|(c)|(d)))"}; 

  private: std::string var_regex_649 {"(?|(?|(a)|(b))|(?|(c)|(d)))"}; 

  private: std::string var_regex_650 {"(.)(?|(.)(.)x|(.)d)(.)"}; 

  private: std::string var_regex_651 {"(\\N)(?|(\\N)(\\N)x|(\\N)d)(\\N)"}; 

  private: std::string var_regex_652 {"(?|(?<foo>x))"}; 

  private: std::string var_regex_653 {"(?|(?<foo>x)|(?<bar>y))"}; 

  private: std::string var_regex_654 {"(?|(?<bar>y)|(?<foo>x))"}; 

  private: std::string var_regex_655 {"(?<bar>)(?|(?<foo>x))"}; 

  private: std::string var_regex_656 {"foo\Kbar"}; 

  private: std::string var_regex_657 {"foo\t\n\r\f\a\ebar"}; 

#line 1749 "pure2-regex.cpp2"
  private: std::string var_regex_658 {"(foo)"}; 

#line 1752 "pure2-regex.cpp2"
  private: std::string var_regex_659 {"(?-n)(foo)(?n)(bar)"}; 

#line 1755 "pure2-regex.cpp2"
  private: std::string var_regex_660 {"(?-n:(foo)(?n:(bar)))"}; 

#line 1758 "pure2-regex.cpp2"
  private: std::string var_regex_661 {"foo # Match foo"}; 

  private: std::string var_regex_662 {"\x41\x42"}; 

  private: std::string var_regex_663 {"\101\o{102}"}; 
  public: auto run() const& -> void;
  public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_0 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_1 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_10 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::word_boundary_matcher_logic<char,false>,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::word_boundary_matcher_logic<char,false>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_100 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::word_boundary_matcher_logic<char,false>,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::word_boundary_matcher_logic<char,false>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_101 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::word_boundary_matcher_logic<char,false>,::cpp2::regex::char_matcher_logic<char,'y','y','Y'>,::cpp2::regex::word_boundary_matcher_logic<char,false>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_102 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::word_boundary_matcher_logic<char,false>,::cpp2::regex::char_matcher_logic<char,'y','y','Y'>,::cpp2::regex::word_boundary_matcher_logic<char,false>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_103 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::word_boundary_matcher_logic<char,false>,::cpp2::regex::char_matcher_logic<char,'y','y','Y'>,::cpp2::regex::word_boundary_matcher_logic<char,false>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_104 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::word_boundary_matcher_logic<char,true>,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::word_boundary_matcher_logic<char,true>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_105 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::word_boundary_matcher_logic<char,true>,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::word_boundary_matcher_logic<char,true>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_106 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::word_boundary_matcher_logic<char,true>,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::word_boundary_matcher_logic<char,true>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_107 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::word_boundary_matcher_logic<char,true>,::cpp2::regex::char_matcher_logic<char,'y','y','Y'>,::cpp2::regex::word_boundary_matcher_logic<char,false>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_108 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::word_boundary_matcher_logic<char,true>,::cpp2::regex::char_matcher_logic<char,'y','y','Y'>,::cpp2::regex::word_boundary_matcher_logic<char,false>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_109 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_11 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::word_boundary_matcher_logic<char,true>,::cpp2::regex::char_matcher_logic<char,'y','y','Y'>,::cpp2::regex::word_boundary_matcher_logic<char,false>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_110 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::word_boundary_matcher_logic<char,true>,::cpp2::regex::char_matcher_logic<char,'y','y','Y'>,::cpp2::regex::word_boundary_matcher_logic<char,false>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_111 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::word_boundary_matcher_logic<char,false>,::cpp2::regex::char_matcher_logic<char,'y','y','Y'>,::cpp2::regex::word_boundary_matcher_logic<char,true>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_112 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::word_boundary_matcher_logic<char,true>,::cpp2::regex::char_matcher_logic<char,'y','y','Y'>,::cpp2::regex::word_boundary_matcher_logic<char,true>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_113 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::word_boundary_matcher_logic<char,false>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_114 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::word_boundary_matcher_logic<char,true>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_115 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::named_class_word<char>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_116 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::named_class_word<char>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_117 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::named_class_not_word<char>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_118 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::named_class_not_word<char>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_119 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,0,-1,true,false,'*'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_12 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::named_class_space<char>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_120 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::named_class_space<char>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_121 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::named_class_not_space<char>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_122 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::named_class_not_space<char>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_123 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::named_class_digits<char>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_124 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::named_class_digits<char>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_125 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::named_class_not_digits<char>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_126 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::named_class_not_digits<char>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_127 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::class_matcher_logic<char,false,::cpp2::regex::short_word_class<char>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_128 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::class_matcher_logic<char,false,::cpp2::regex::short_word_class<char>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_129 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,0,-1,true,false,'*'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_13 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::class_matcher_logic<char,false,::cpp2::regex::short_not_word_class<char>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_130 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::class_matcher_logic<char,false,::cpp2::regex::short_not_word_class<char>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_131 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::class_matcher_logic<char,false,::cpp2::regex::short_space_class<char>>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_132 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::class_matcher_logic<char,false,::cpp2::regex::short_space_class<char>>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_133 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::class_matcher_logic<char,false,::cpp2::regex::short_not_space_class<char>>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_134 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::class_matcher_logic<char,false,::cpp2::regex::short_not_space_class<char>>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_135 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::class_matcher_logic<char,false,::cpp2::regex::short_digits_class<char>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_136 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::class_matcher_logic<char,false,::cpp2::regex::short_digits_class<char>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_137 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::class_matcher_logic<char,false,::cpp2::regex::short_not_digits_class<char>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_138 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::class_matcher_logic<char,false,::cpp2::regex::short_not_digits_class<char>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_139 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,0,-1,true,false,'*'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_14 {}; public: ::cpp2::regex::regular_expression<char,0,1,1,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::alternative_matcher_logic<char,0,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'c','c','C'>,::cpp2::regex::char_matcher_logic<char,'d','d','D'>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_140 {}; public: ::cpp2::regex::regular_expression<char,0,1,1,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::alternative_matcher_logic<char,0,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'c','c','C'>,::cpp2::regex::char_matcher_logic<char,'d','d','D'>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_141 {}; public: ::cpp2::regex::regular_expression<char,0,2,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char>,::cpp2::regex::group_matcher_end_logic<char,1>>,::cpp2::regex::char_matcher_logic<char,'e','e','E'>,::cpp2::regex::char_matcher_logic<char,'f','f','F'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_142 {}; public: ::cpp2::regex::regular_expression<char,0,2,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char>,::cpp2::regex::group_matcher_end_logic<char,1>>,::cpp2::regex::char_matcher_logic<char,'e','e','E'>,::cpp2::regex::char_matcher_logic<char,'f','f','F'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_143 {}; public: ::cpp2::regex::regular_expression<char,0,2,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char>,::cpp2::regex::group_matcher_end_logic<char,1>>,::cpp2::regex::char_matcher_logic<char,'e','e','E'>,::cpp2::regex::char_matcher_logic<char,'f','f','F'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_144 {}; public: ::cpp2::regex::regular_expression<char,0,2,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char>,::cpp2::regex::group_matcher_end_logic<char,1>>,::cpp2::regex::char_matcher_logic<char,'e','e','E'>,::cpp2::regex::char_matcher_logic<char,'f','f','F'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_145 {}; public: ::cpp2::regex::regular_expression<char,0,2,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char>,::cpp2::regex::group_matcher_end_logic<char,1>>,::cpp2::regex::char_matcher_logic<char,'e','e','E'>,::cpp2::regex::char_matcher_logic<char,'f','f','F'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_146 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::line_end_matcher_logic<char,true,true>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_147 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::special_syntax_wrapper<char,"\\(",::cpp2::regex::char_matcher_logic<char,'\(','\(','\('>>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_148 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::special_syntax_wrapper<char,"\\(",::cpp2::regex::char_matcher_logic<char,'\(','\(','\('>>,0,-1,true,false,'*'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_149 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,0,-1,true,false,'*'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_15 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::special_syntax_wrapper<char,"\\(",::cpp2::regex::char_matcher_logic<char,'\(','\(','\('>>,0,-1,true,false,'*'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_150 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::special_syntax_wrapper<char,"\\\\",::cpp2::regex::char_matcher_logic<char,'\\','\\','\\'>>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_151 {}; public: ::cpp2::regex::regular_expression<char,0,3,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,2,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>>,::cpp2::regex::group_matcher_end_logic<char,2>>>,::cpp2::regex::group_matcher_end_logic<char,1>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_152 {}; public: ::cpp2::regex::regular_expression<char,0,3,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,2,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>>,::cpp2::regex::group_matcher_end_logic<char,2>>>,::cpp2::regex::group_matcher_end_logic<char,1>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_153 {}; public: ::cpp2::regex::regular_expression<char,0,3,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,2,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>>,::cpp2::regex::group_matcher_end_logic<char,2>>>,::cpp2::regex::group_matcher_end_logic<char,1>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_154 {}; public: ::cpp2::regex::regular_expression<char,0,3,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'f','f','F'>,::cpp2::regex::char_matcher_logic<char,'o','o','O'>,::cpp2::regex::char_matcher_logic<char,'o','o','O'>>,::cpp2::regex::group_matcher_end_logic<char,1>>,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,2,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::group_ref_matcher_logic<char,1,"\\g-2">>,::cpp2::regex::group_matcher_end_logic<char,2>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_155 {}; public: ::cpp2::regex::regular_expression<char,0,5,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'f','f','F'>,::cpp2::regex::char_matcher_logic<char,'o','o','O'>,::cpp2::regex::char_matcher_logic<char,'o','o','O'>>,::cpp2::regex::group_matcher_end_logic<char,1>>,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,2,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::group_ref_matcher_logic<char,1,"\\g-2">>,::cpp2::regex::group_matcher_end_logic<char,2>>,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,3,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'f','f','F'>,::cpp2::regex::char_matcher_logic<char,'o','o','O'>,::cpp2::regex::char_matcher_logic<char,'o','o','O'>>,::cpp2::regex::group_matcher_end_logic<char,3>>,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,4,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::group_ref_matcher_logic<char,3,"\\g-2">>,::cpp2::regex::group_matcher_end_logic<char,4>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_156 {}; public: ::cpp2::regex::regular_expression<char,0,5,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,2,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::class_matcher_logic<char,false,::cpp2::regex::single_class_entry<char,'a'>,::cpp2::regex::single_class_entry<char,'b'>,::cpp2::regex::single_class_entry<char,'c'>>,1,-1,true,false,'+'>>,::cpp2::regex::group_matcher_end_logic<char,2>>,::cpp2::regex::char_matcher_logic<char,' ',' ',' '>,::cpp2::regex::group_ref_matcher_logic<char,2,"\\g-1">>,::cpp2::regex::group_matcher_end_logic<char,1>>,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,3,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,4,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::class_matcher_logic<char,false,::cpp2::regex::single_class_entry<char,'a'>,::cpp2::regex::single_class_entry<char,'b'>,::cpp2::regex::single_class_entry<char,'c'>>,1,-1,true,false,'+'>>,::cpp2::regex::group_matcher_end_logic<char,4>>,::cpp2::regex::char_matcher_logic<char,' ',' ',' '>,::cpp2::regex::group_ref_matcher_logic<char,4,"\\g{-1}">>,::cpp2::regex::group_matcher_end_logic<char,3>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_157 {}; public: ::cpp2::regex::regular_expression<char,0,4,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>>,::cpp2::regex::group_matcher_end_logic<char,1>>,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,2,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>>,::cpp2::regex::group_matcher_end_logic<char,2>>,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,3,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,3>>,::cpp2::regex::group_ref_matcher_logic<char,1,"\\g1">,::cpp2::regex::group_ref_matcher_logic<char,2,"\\g2">,::cpp2::regex::group_ref_matcher_logic<char,3,"\\g3">>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_158 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_159 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,0,-1,true,false,'*'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_16 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_160 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_161 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_162 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_163 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_164 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,0,-1,true,false,'*'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_165 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,0,-1,true,false,'*'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_166 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,0,-1,true,false,'*'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_167 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,0,-1,false,false,'*'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_168 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,0,-1,false,false>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_169 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,0,-1,true,false,'*'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_17 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,1,-1,false,false,'+'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_170 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,1,-1,true,false,'+'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_171 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,1,-1,true,false,'+'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_172 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,1,-1,true,false>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_173 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,1,-1,true,false,'+'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_174 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,1,-1,false,false>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_175 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,1,3,false,false>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_176 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,3,4,false,false>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_177 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,4,5,false,false>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_178 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,0,1,false,false,'?'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_179 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,0,-1,true,false,'*'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_18 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,0,1,false,false,'?'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_180 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,0,1,false,false>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_181 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,0,1,false,false,'?'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_182 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,0,1,false,false,'?'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_183 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,0,1,false,false>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_184 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::line_start_matcher_logic<char,true>,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>,::cpp2::regex::line_end_matcher_logic<char,true,true>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_185 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::line_start_matcher_logic<char,true>,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>,::cpp2::regex::line_end_matcher_logic<char,true,true>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_186 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::line_start_matcher_logic<char,true>,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_187 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::line_start_matcher_logic<char,true>,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>,::cpp2::regex::line_end_matcher_logic<char,true,true>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_188 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>,::cpp2::regex::line_end_matcher_logic<char,true,true>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_189 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,0,-1,true,false,'*'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_19 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::line_start_matcher_logic<char,true>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_190 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::line_end_matcher_logic<char,true,true>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_191 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::any_matcher_logic<char>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_192 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::any_matcher_logic<char>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_193 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::named_class_no_new_line<char>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_194 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::any_matcher_logic<char>,0,-1,false,false,'*'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_195 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::any_matcher_logic<char>,0,-1,true,false,'*'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_196 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::class_matcher_logic<char,false,::cpp2::regex::single_class_entry<char,'b'>,::cpp2::regex::single_class_entry<char,'c'>>,::cpp2::regex::char_matcher_logic<char,'d','d','D'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_197 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::class_matcher_logic<char,false,::cpp2::regex::single_class_entry<char,'b'>,::cpp2::regex::single_class_entry<char,'c'>>,::cpp2::regex::char_matcher_logic<char,'d','d','D'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_198 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::class_matcher_logic<char,false,::cpp2::regex::range_class_entry<char,'b','d'>>,::cpp2::regex::char_matcher_logic<char,'e','e','E'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_199 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_2 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,0,-1,true,false,'*'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_20 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::class_matcher_logic<char,false,::cpp2::regex::range_class_entry<char,'b','d'>>,::cpp2::regex::char_matcher_logic<char,'e','e','E'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_200 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::class_matcher_logic<char,false,::cpp2::regex::range_class_entry<char,'b','d'>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_201 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::class_matcher_logic<char,false,::cpp2::regex::single_class_entry<char,'-'>,::cpp2::regex::single_class_entry<char,'b'>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_202 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::class_matcher_logic<char,false,::cpp2::regex::single_class_entry<char,'b'>,::cpp2::regex::single_class_entry<char,'-'>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_203 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,']',']',']'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_204 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::class_matcher_logic<char,false,::cpp2::regex::single_class_entry<char,']'>>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_205 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::class_matcher_logic<char,true,::cpp2::regex::single_class_entry<char,'b'>,::cpp2::regex::single_class_entry<char,'c'>>,::cpp2::regex::char_matcher_logic<char,'d','d','D'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_206 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::class_matcher_logic<char,true,::cpp2::regex::single_class_entry<char,'b'>,::cpp2::regex::single_class_entry<char,'c'>>,::cpp2::regex::char_matcher_logic<char,'d','d','D'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_207 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::class_matcher_logic<char,true,::cpp2::regex::single_class_entry<char,'-'>,::cpp2::regex::single_class_entry<char,'b'>>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_208 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::class_matcher_logic<char,true,::cpp2::regex::single_class_entry<char,'-'>,::cpp2::regex::single_class_entry<char,'b'>>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_209 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,0,-1,true,false,'*'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_21 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::class_matcher_logic<char,true,::cpp2::regex::single_class_entry<char,']'>,::cpp2::regex::single_class_entry<char,'b'>>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_210 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::class_matcher_logic<char,true,::cpp2::regex::single_class_entry<char,']'>,::cpp2::regex::single_class_entry<char,'b'>>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_211 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,1,1,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::alternative_matcher_logic<char,0,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'c','c','C'>,::cpp2::regex::char_matcher_logic<char,'d','d','D'>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_212 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,1,1,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::alternative_matcher_logic<char,0,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'c','c','C'>,::cpp2::regex::char_matcher_logic<char,'d','d','D'>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_213 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,2,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char>,::cpp2::regex::group_matcher_end_logic<char,1>>,::cpp2::regex::char_matcher_logic<char,'e','e','E'>,::cpp2::regex::char_matcher_logic<char,'f','f','F'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_214 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::line_end_matcher_logic<char,true,true>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_215 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::special_syntax_wrapper<char,"\\(",::cpp2::regex::char_matcher_logic<char,'\(','\(','\('>>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_216 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::special_syntax_wrapper<char,"\\(",::cpp2::regex::char_matcher_logic<char,'\(','\(','\('>>,0,-1,true,false,'*'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_217 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::special_syntax_wrapper<char,"\\(",::cpp2::regex::char_matcher_logic<char,'\(','\(','\('>>,0,-1,true,false,'*'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_218 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::special_syntax_wrapper<char,"\\\\",::cpp2::regex::char_matcher_logic<char,'\\','\\','\\'>>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_219 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,0,-1,true,false,'*'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_22 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,3,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,2,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>>,::cpp2::regex::group_matcher_end_logic<char,2>>>,::cpp2::regex::group_matcher_end_logic<char,1>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_220 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,3,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>>,::cpp2::regex::group_matcher_end_logic<char,1>>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,2,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,2>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_221 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,1,-1,true,false,'+'>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,1,-1,true,false,'+'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_222 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,1,-1,true,false>,::cpp2::regex::range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,1,-1,true,false>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_223 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::any_matcher_logic<char>,1,-1,false,false,'+'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_224 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::any_matcher_logic<char>,0,-1,false,false,'*'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_225 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::range_matcher_logic<char,::cpp2::regex::any_matcher_logic<char>,0,5,false,false>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_226 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,2,1,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::alternative_matcher_logic<char,0,::cpp2::regex::matcher_list<char,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,1,-1,true,false,'+'>>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>>>,::cpp2::regex::group_matcher_end_logic<char,1>>,0,-1,true,false,'*'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_227 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,2,1,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::range_matcher_logic<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::alternative_matcher_logic<char,0,::cpp2::regex::matcher_list<char,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,1,-1,true,false,'+'>>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>>>,::cpp2::regex::group_matcher_end_logic<char,1>>,0,-1,true,false>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_228 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,2,1,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::alternative_matcher_logic<char,0,::cpp2::regex::matcher_list<char,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,1,-1,true,false,'+'>>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>>>,::cpp2::regex::group_matcher_end_logic<char,1>>,1,-1,true,false,'+'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_229 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,0,-1,true,false,'*'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_23 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,2,1,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::range_matcher_logic<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::alternative_matcher_logic<char,0,::cpp2::regex::matcher_list<char,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,1,-1,true,false,'+'>>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>>>,::cpp2::regex::group_matcher_end_logic<char,1>>,1,-1,true,false>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_230 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,2,1,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::alternative_matcher_logic<char,0,::cpp2::regex::matcher_list<char,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,1,-1,true,false,'+'>>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>>>,::cpp2::regex::group_matcher_end_logic<char,1>>,0,1,true,false,'?'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_231 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,2,1,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::range_matcher_logic<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::alternative_matcher_logic<char,0,::cpp2::regex::matcher_list<char,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,1,-1,true,false,'+'>>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>>>,::cpp2::regex::group_matcher_end_logic<char,1>>,0,1,true,false>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_232 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,2,1,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::range_matcher_logic<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::alternative_matcher_logic<char,0,::cpp2::regex::matcher_list<char,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,1,-1,true,false,'+'>>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>>>,::cpp2::regex::group_matcher_end_logic<char,1>>,0,1,false,false>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_233 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::class_matcher_logic<char,true,::cpp2::regex::single_class_entry<char,'a'>,::cpp2::regex::single_class_entry<char,'b'>>,0,-1,true,false,'*'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_234 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_235 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,0,-1,true,false,'*'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_236 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,2,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::class_matcher_logic<char,false,::cpp2::regex::single_class_entry<char,'a'>,::cpp2::regex::single_class_entry<char,'b'>,::cpp2::regex::single_class_entry<char,'c'>>>,::cpp2::regex::group_matcher_end_logic<char,1>>,0,-1,true,false,'*'>,::cpp2::regex::char_matcher_logic<char,'d','d','D'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_237 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,2,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::class_matcher_logic<char,false,::cpp2::regex::single_class_entry<char,'a'>,::cpp2::regex::single_class_entry<char,'b'>,::cpp2::regex::single_class_entry<char,'c'>>>,::cpp2::regex::group_matcher_end_logic<char,1>>,0,-1,true,false,'*'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>,::cpp2::regex::char_matcher_logic<char,'d','d','D'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_238 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,1,1,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::alternative_matcher_logic<char,0,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'d','d','D'>>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'e','e','E'>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_239 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::range_matcher_logic<char,::cpp2::regex::any_matcher_logic<char>,1,1,true,false>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_24 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,2,1,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::alternative_matcher_logic<char,0,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'d','d','D'>>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'e','e','E'>>>,::cpp2::regex::group_matcher_end_logic<char,1>>,::cpp2::regex::char_matcher_logic<char,'f','f','F'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_240 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'d','d','D'>,0,-1,true,false,'*'>,::cpp2::regex::char_matcher_logic<char,'e','e','E'>,::cpp2::regex::char_matcher_logic<char,'f','f','F'>,::cpp2::regex::char_matcher_logic<char,'g','g','G'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_241 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,0,-1,true,false,'*'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_242 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,0,-1,true,false,'*'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_243 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,2,1,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::alternative_matcher_logic<char,0,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'c','c','C'>,::cpp2::regex::char_matcher_logic<char,'d','d','D'>>>,::cpp2::regex::group_matcher_end_logic<char,1>>,::cpp2::regex::char_matcher_logic<char,'e','e','E'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_244 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::class_matcher_logic<char,false,::cpp2::regex::single_class_entry<char,'a'>,::cpp2::regex::single_class_entry<char,'b'>,::cpp2::regex::single_class_entry<char,'h'>,::cpp2::regex::single_class_entry<char,'g'>,::cpp2::regex::single_class_entry<char,'e'>,::cpp2::regex::single_class_entry<char,'f'>,::cpp2::regex::single_class_entry<char,'d'>,::cpp2::regex::single_class_entry<char,'c'>>,::cpp2::regex::char_matcher_logic<char,'i','i','I'>,::cpp2::regex::char_matcher_logic<char,'j','j','J'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_245 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,2,1,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::line_start_matcher_logic<char,true>,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::alternative_matcher_logic<char,0,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'c','c','C'>,::cpp2::regex::char_matcher_logic<char,'d','d','D'>>>,::cpp2::regex::group_matcher_end_logic<char,1>>,::cpp2::regex::char_matcher_logic<char,'e','e','E'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_246 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,2,1,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::alternative_matcher_logic<char,0,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::matcher_list<char,::cpp2::regex::empty_matcher_logic<char>>>,::cpp2::regex::group_matcher_end_logic<char,1>>,::cpp2::regex::char_matcher_logic<char,'e','e','E'>,::cpp2::regex::char_matcher_logic<char,'f','f','F'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_247 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,2,1,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::alternative_matcher_logic<char,0,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>>>,::cpp2::regex::group_matcher_end_logic<char,1>>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'c','c','C'>,0,-1,true,false,'*'>,::cpp2::regex::char_matcher_logic<char,'d','d','D'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_248 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,2,1,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::alternative_matcher_logic<char,0,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,0,-1,true,false,'*'>>>,::cpp2::regex::group_matcher_end_logic<char,1>>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_249 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::range_matcher_logic<char,::cpp2::regex::any_matcher_logic<char>,1,1,true,false>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_25 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,2,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::class_matcher_logic<char,false,::cpp2::regex::single_class_entry<char,'b'>,::cpp2::regex::single_class_entry<char,'c'>>,0,-1,true,false,'*'>>,::cpp2::regex::group_matcher_end_logic<char,1>>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'c','c','C'>,0,-1,true,false,'*'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_250 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,3,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::class_matcher_logic<char,false,::cpp2::regex::single_class_entry<char,'b'>,::cpp2::regex::single_class_entry<char,'c'>>,0,-1,true,false,'*'>>,::cpp2::regex::group_matcher_end_logic<char,1>>,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,2,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'c','c','C'>,0,-1,true,false,'*'>,::cpp2::regex::char_matcher_logic<char,'d','d','D'>>,::cpp2::regex::group_matcher_end_logic<char,2>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_251 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,3,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::class_matcher_logic<char,false,::cpp2::regex::single_class_entry<char,'b'>,::cpp2::regex::single_class_entry<char,'c'>>,1,-1,true,false,'+'>>,::cpp2::regex::group_matcher_end_logic<char,1>>,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,2,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'c','c','C'>,0,-1,true,false,'*'>,::cpp2::regex::char_matcher_logic<char,'d','d','D'>>,::cpp2::regex::group_matcher_end_logic<char,2>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_252 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,3,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::class_matcher_logic<char,false,::cpp2::regex::single_class_entry<char,'b'>,::cpp2::regex::single_class_entry<char,'c'>>,0,-1,true,false,'*'>>,::cpp2::regex::group_matcher_end_logic<char,1>>,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,2,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'c','c','C'>,1,-1,true,false,'+'>,::cpp2::regex::char_matcher_logic<char,'d','d','D'>>,::cpp2::regex::group_matcher_end_logic<char,2>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_253 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::class_matcher_logic<char,false,::cpp2::regex::single_class_entry<char,'b'>,::cpp2::regex::single_class_entry<char,'c'>,::cpp2::regex::single_class_entry<char,'d'>>,0,-1,true,false,'*'>,::cpp2::regex::char_matcher_logic<char,'d','d','D'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>,::cpp2::regex::char_matcher_logic<char,'d','d','D'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>,::cpp2::regex::char_matcher_logic<char,'d','d','D'>,::cpp2::regex::char_matcher_logic<char,'e','e','E'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_254 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::class_matcher_logic<char,false,::cpp2::regex::single_class_entry<char,'b'>,::cpp2::regex::single_class_entry<char,'c'>,::cpp2::regex::single_class_entry<char,'d'>>,1,-1,true,false,'+'>,::cpp2::regex::char_matcher_logic<char,'d','d','D'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>,::cpp2::regex::char_matcher_logic<char,'d','d','D'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>,::cpp2::regex::char_matcher_logic<char,'d','d','D'>,::cpp2::regex::char_matcher_logic<char,'e','e','E'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_255 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,2,1,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::alternative_matcher_logic<char,0,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>>>,::cpp2::regex::group_matcher_end_logic<char,1>>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,0,-1,true,false,'*'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_256 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,5,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,2,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>>,::cpp2::regex::group_matcher_end_logic<char,2>>,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,3,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>>,::cpp2::regex::group_matcher_end_logic<char,3>>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,1>>,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,4,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'d','d','D'>>,::cpp2::regex::group_matcher_end_logic<char,4>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_257 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::class_matcher_logic<char,false,::cpp2::regex::range_class_entry<char,'a','z'>,::cpp2::regex::range_class_entry<char,'A','Z'>,::cpp2::regex::single_class_entry<char,'_'>>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::class_matcher_logic<char,false,::cpp2::regex::range_class_entry<char,'a','z'>,::cpp2::regex::range_class_entry<char,'A','Z'>,::cpp2::regex::range_class_entry<char,'0','9'>,::cpp2::regex::single_class_entry<char,'_'>>,0,-1,true,false,'*'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_258 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,2,2,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::alternative_matcher_logic<char,1,::cpp2::regex::matcher_list<char,::cpp2::regex::line_start_matcher_logic<char,true>,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::alternative_matcher_logic<char,0,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'c','c','C'>,1,-1,true,false,'+'>>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::class_matcher_logic<char,false,::cpp2::regex::single_class_entry<char,'e'>,::cpp2::regex::single_class_entry<char,'h'>>>>,::cpp2::regex::group_matcher_end_logic<char,1>>,::cpp2::regex::char_matcher_logic<char,'g','g','G'>>,::cpp2::regex::matcher_list<char,::cpp2::regex::any_matcher_logic<char>,::cpp2::regex::char_matcher_logic<char,'h','h','H'>,::cpp2::regex::line_end_matcher_logic<char,true,true>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_259 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::range_matcher_logic<char,::cpp2::regex::any_matcher_logic<char>,1,1,true,false>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_26 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,3,2,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::alternative_matcher_logic<char,1,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'c','c','C'>,1,-1,true,false,'+'>,::cpp2::regex::char_matcher_logic<char,'d','d','D'>,::cpp2::regex::line_end_matcher_logic<char,true,true>>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'e','e','E'>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'f','f','F'>,0,-1,true,false,'*'>,::cpp2::regex::char_matcher_logic<char,'g','g','G'>,::cpp2::regex::any_matcher_logic<char>>,::cpp2::regex::matcher_list<char,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'h','h','H'>,0,1,true,false,'?'>,::cpp2::regex::char_matcher_logic<char,'i','i','I'>,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,2,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::alternative_matcher_logic<char,0,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'j','j','J'>>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'k','k','K'>>>,::cpp2::regex::group_matcher_end_logic<char,2>>>>,::cpp2::regex::group_matcher_end_logic<char,1>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_260 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,3,2,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::alternative_matcher_logic<char,1,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'c','c','C'>,1,-1,true,false,'+'>,::cpp2::regex::char_matcher_logic<char,'d','d','D'>,::cpp2::regex::line_end_matcher_logic<char,true,true>>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'e','e','E'>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'f','f','F'>,0,-1,true,false,'*'>,::cpp2::regex::char_matcher_logic<char,'g','g','G'>,::cpp2::regex::any_matcher_logic<char>>,::cpp2::regex::matcher_list<char,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'h','h','H'>,0,1,true,false,'?'>,::cpp2::regex::char_matcher_logic<char,'i','i','I'>,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,2,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::alternative_matcher_logic<char,0,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'j','j','J'>>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'k','k','K'>>>,::cpp2::regex::group_matcher_end_logic<char,2>>>>,::cpp2::regex::group_matcher_end_logic<char,1>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_261 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,3,2,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::alternative_matcher_logic<char,1,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'c','c','C'>,1,-1,true,false,'+'>,::cpp2::regex::char_matcher_logic<char,'d','d','D'>,::cpp2::regex::line_end_matcher_logic<char,true,true>>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'e','e','E'>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'f','f','F'>,0,-1,true,false,'*'>,::cpp2::regex::char_matcher_logic<char,'g','g','G'>,::cpp2::regex::any_matcher_logic<char>>,::cpp2::regex::matcher_list<char,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'h','h','H'>,0,1,true,false,'?'>,::cpp2::regex::char_matcher_logic<char,'i','i','I'>,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,2,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::alternative_matcher_logic<char,0,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'j','j','J'>>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'k','k','K'>>>,::cpp2::regex::group_matcher_end_logic<char,2>>>>,::cpp2::regex::group_matcher_end_logic<char,1>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_262 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,3,2,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::alternative_matcher_logic<char,1,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'c','c','C'>,1,-1,true,false,'+'>,::cpp2::regex::char_matcher_logic<char,'d','d','D'>,::cpp2::regex::line_end_matcher_logic<char,true,true>>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'e','e','E'>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'f','f','F'>,0,-1,true,false,'*'>,::cpp2::regex::char_matcher_logic<char,'g','g','G'>,::cpp2::regex::any_matcher_logic<char>>,::cpp2::regex::matcher_list<char,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'h','h','H'>,0,1,true,false,'?'>,::cpp2::regex::char_matcher_logic<char,'i','i','I'>,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,2,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::alternative_matcher_logic<char,0,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'j','j','J'>>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'k','k','K'>>>,::cpp2::regex::group_matcher_end_logic<char,2>>>>,::cpp2::regex::group_matcher_end_logic<char,1>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_263 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,3,2,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::alternative_matcher_logic<char,1,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'c','c','C'>,1,-1,true,false,'+'>,::cpp2::regex::char_matcher_logic<char,'d','d','D'>,::cpp2::regex::line_end_matcher_logic<char,true,true>>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'e','e','E'>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'f','f','F'>,0,-1,true,false,'*'>,::cpp2::regex::char_matcher_logic<char,'g','g','G'>,::cpp2::regex::any_matcher_logic<char>>,::cpp2::regex::matcher_list<char,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'h','h','H'>,0,1,true,false,'?'>,::cpp2::regex::char_matcher_logic<char,'i','i','I'>,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,2,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::alternative_matcher_logic<char,0,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'j','j','J'>>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'k','k','K'>>>,::cpp2::regex::group_matcher_end_logic<char,2>>>>,::cpp2::regex::group_matcher_end_logic<char,1>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_264 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,11,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,2,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,3,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,4,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,5,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,6,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,7,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,8,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,9,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,10,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>>,::cpp2::regex::group_matcher_end_logic<char,10>>>,::cpp2::regex::group_matcher_end_logic<char,9>>>,::cpp2::regex::group_matcher_end_logic<char,8>>>,::cpp2::regex::group_matcher_end_logic<char,7>>>,::cpp2::regex::group_matcher_end_logic<char,6>>>,::cpp2::regex::group_matcher_end_logic<char,5>>>,::cpp2::regex::group_matcher_end_logic<char,4>>>,::cpp2::regex::group_matcher_end_logic<char,3>>>,::cpp2::regex::group_matcher_end_logic<char,2>>>,::cpp2::regex::group_matcher_end_logic<char,1>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_265 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,11,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,2,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,3,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,4,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,5,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,6,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,7,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,8,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,9,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,10,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>>,::cpp2::regex::group_matcher_end_logic<char,10>>>,::cpp2::regex::group_matcher_end_logic<char,9>>>,::cpp2::regex::group_matcher_end_logic<char,8>>>,::cpp2::regex::group_matcher_end_logic<char,7>>>,::cpp2::regex::group_matcher_end_logic<char,6>>>,::cpp2::regex::group_matcher_end_logic<char,5>>>,::cpp2::regex::group_matcher_end_logic<char,4>>>,::cpp2::regex::group_matcher_end_logic<char,3>>>,::cpp2::regex::group_matcher_end_logic<char,2>>>,::cpp2::regex::group_matcher_end_logic<char,1>>,::cpp2::regex::group_ref_matcher_logic<char,10,"\\10">>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_266 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,10,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,2,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,3,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,4,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,5,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,6,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,7,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,8,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,9,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>>,::cpp2::regex::group_matcher_end_logic<char,9>>>,::cpp2::regex::group_matcher_end_logic<char,8>>>,::cpp2::regex::group_matcher_end_logic<char,7>>>,::cpp2::regex::group_matcher_end_logic<char,6>>>,::cpp2::regex::group_matcher_end_logic<char,5>>>,::cpp2::regex::group_matcher_end_logic<char,4>>>,::cpp2::regex::group_matcher_end_logic<char,3>>>,::cpp2::regex::group_matcher_end_logic<char,2>>>,::cpp2::regex::group_matcher_end_logic<char,1>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_267 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'m','m','M'>,::cpp2::regex::char_matcher_logic<char,'u','u','U'>,::cpp2::regex::char_matcher_logic<char,'l','l','L'>,::cpp2::regex::char_matcher_logic<char,'t','t','T'>,::cpp2::regex::char_matcher_logic<char,'i','i','I'>,::cpp2::regex::char_matcher_logic<char,'p','p','P'>,::cpp2::regex::char_matcher_logic<char,'l','l','L'>,::cpp2::regex::char_matcher_logic<char,'e','e','E'>,::cpp2::regex::char_matcher_logic<char,' ',' ',' '>,::cpp2::regex::char_matcher_logic<char,'w','w','W'>,::cpp2::regex::char_matcher_logic<char,'o','o','O'>,::cpp2::regex::char_matcher_logic<char,'r','r','R'>,::cpp2::regex::char_matcher_logic<char,'d','d','D'>,::cpp2::regex::char_matcher_logic<char,'s','s','S'>,::cpp2::regex::char_matcher_logic<char,' ',' ',' '>,::cpp2::regex::char_matcher_logic<char,'o','o','O'>,::cpp2::regex::char_matcher_logic<char,'f','f','F'>,::cpp2::regex::char_matcher_logic<char,' ',' ',' '>,::cpp2::regex::char_matcher_logic<char,'t','t','T'>,::cpp2::regex::char_matcher_logic<char,'e','e','E'>,::cpp2::regex::char_matcher_logic<char,'x','x','X'>,::cpp2::regex::char_matcher_logic<char,'t','t','T'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_268 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'m','m','M'>,::cpp2::regex::char_matcher_logic<char,'u','u','U'>,::cpp2::regex::char_matcher_logic<char,'l','l','L'>,::cpp2::regex::char_matcher_logic<char,'t','t','T'>,::cpp2::regex::char_matcher_logic<char,'i','i','I'>,::cpp2::regex::char_matcher_logic<char,'p','p','P'>,::cpp2::regex::char_matcher_logic<char,'l','l','L'>,::cpp2::regex::char_matcher_logic<char,'e','e','E'>,::cpp2::regex::char_matcher_logic<char,' ',' ',' '>,::cpp2::regex::char_matcher_logic<char,'w','w','W'>,::cpp2::regex::char_matcher_logic<char,'o','o','O'>,::cpp2::regex::char_matcher_logic<char,'r','r','R'>,::cpp2::regex::char_matcher_logic<char,'d','d','D'>,::cpp2::regex::char_matcher_logic<char,'s','s','S'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_269 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::range_matcher_logic<char,::cpp2::regex::any_matcher_logic<char>,3,4,true,false>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_27 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,3,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::any_matcher_logic<char>,0,-1,true,false,'*'>>,::cpp2::regex::group_matcher_end_logic<char,1>>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,2,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::any_matcher_logic<char>,0,-1,true,false,'*'>>,::cpp2::regex::group_matcher_end_logic<char,2>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_270 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,3,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::special_syntax_wrapper<char,"\\(",::cpp2::regex::char_matcher_logic<char,'\(','\(','\('>>,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::any_matcher_logic<char>,0,-1,true,false,'*'>>,::cpp2::regex::group_matcher_end_logic<char,1>>,::cpp2::regex::char_matcher_logic<char,',',',',','>,::cpp2::regex::char_matcher_logic<char,' ',' ',' '>,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,2,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::any_matcher_logic<char>,0,-1,true,false,'*'>>,::cpp2::regex::group_matcher_end_logic<char,2>>,::cpp2::regex::special_syntax_wrapper<char,"\\)",::cpp2::regex::char_matcher_logic<char,'\)','\)','\)'>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_271 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::class_matcher_logic<char,false,::cpp2::regex::single_class_entry<char,'k'>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_272 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>,::cpp2::regex::char_matcher_logic<char,'d','d','D'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_273 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,2,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,1>>,::cpp2::regex::char_matcher_logic<char,'d','d','D'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_274 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::class_matcher_logic<char,false,::cpp2::regex::single_class_entry<char,'-'>>,0,1,true,false,'?'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_275 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,2,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,1>>,::cpp2::regex::group_ref_matcher_logic<char,1,"\\1">>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_276 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,2,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::class_matcher_logic<char,false,::cpp2::regex::range_class_entry<char,'a','c'>>,0,-1,true,false,'*'>>,::cpp2::regex::group_matcher_end_logic<char,1>>,::cpp2::regex::group_ref_matcher_logic<char,1,"\\1">>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_277 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,1,-1,true,true,'+'>,::cpp2::regex::char_matcher_logic<char,'a','a','A'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_278 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,0,-1,true,true,'*'>,::cpp2::regex::char_matcher_logic<char,'a','a','A'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_279 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::range_matcher_logic<char,::cpp2::regex::any_matcher_logic<char>,3,4,true,false>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_28 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,1,5,true,true>,::cpp2::regex::char_matcher_logic<char,'a','a','A'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_280 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,0,1,true,true,'?'>,::cpp2::regex::char_matcher_logic<char,'a','a','A'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_281 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,1,-1,true,true,'+'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_282 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,0,-1,true,true,'*'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_283 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,1,5,true,true>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_284 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,0,1,true,true,'?'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_285 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'f','f','F'>,::cpp2::regex::char_matcher_logic<char,'o','o','O'>,::cpp2::regex::char_matcher_logic<char,'o','o','O'>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,1,-1,true,true,'+'>,::cpp2::regex::char_matcher_logic<char,'a','a','A'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_286 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'f','f','F'>,::cpp2::regex::char_matcher_logic<char,'o','o','O'>,::cpp2::regex::char_matcher_logic<char,'o','o','O'>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,0,-1,true,true,'*'>,::cpp2::regex::char_matcher_logic<char,'a','a','A'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_287 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'f','f','F'>,::cpp2::regex::char_matcher_logic<char,'o','o','O'>,::cpp2::regex::char_matcher_logic<char,'o','o','O'>,::cpp2::regex::range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,1,5,true,true>,::cpp2::regex::char_matcher_logic<char,'a','a','A'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_288 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'f','f','F'>,::cpp2::regex::char_matcher_logic<char,'o','o','O'>,::cpp2::regex::char_matcher_logic<char,'o','o','O'>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,0,1,true,true,'?'>,::cpp2::regex::char_matcher_logic<char,'a','a','A'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_289 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::range_matcher_logic<char,::cpp2::regex::any_matcher_logic<char>,3,4,true,false>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_29 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'f','f','F'>,::cpp2::regex::char_matcher_logic<char,'o','o','O'>,::cpp2::regex::char_matcher_logic<char,'o','o','O'>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,1,-1,true,true,'+'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_290 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'f','f','F'>,::cpp2::regex::char_matcher_logic<char,'o','o','O'>,::cpp2::regex::char_matcher_logic<char,'o','o','O'>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,0,-1,true,true,'*'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_291 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'f','f','F'>,::cpp2::regex::char_matcher_logic<char,'o','o','O'>,::cpp2::regex::char_matcher_logic<char,'o','o','O'>,::cpp2::regex::range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,1,5,true,true>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_292 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'f','f','F'>,::cpp2::regex::char_matcher_logic<char,'o','o','O'>,::cpp2::regex::char_matcher_logic<char,'o','o','O'>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,0,1,true,true,'?'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_293 {}; public: ::cpp2::regex::regular_expression<char,0,3,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'A','a','A'>>,::cpp2::regex::group_matcher_end_logic<char,1>>,1,-1,true,true,'+'>,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,2,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'A','a','A'>>,::cpp2::regex::group_matcher_end_logic<char,2>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_294 {}; public: ::cpp2::regex::regular_expression<char,0,3,2,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::alternative_matcher_logic<char,0,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'A','a','A'>>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'B','b','B'>>>,::cpp2::regex::group_matcher_end_logic<char,1>>,1,-1,true,true,'+'>,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,2,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::alternative_matcher_logic<char,1,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'A','a','A'>>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'B','b','B'>>>,::cpp2::regex::group_matcher_end_logic<char,2>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_295 {}; public: ::cpp2::regex::regular_expression<char,0,3,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'A','a','A'>>,::cpp2::regex::group_matcher_end_logic<char,1>>,0,-1,true,true,'*'>,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,2,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'A','a','A'>>,::cpp2::regex::group_matcher_end_logic<char,2>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_296 {}; public: ::cpp2::regex::regular_expression<char,0,3,2,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::alternative_matcher_logic<char,0,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'A','a','A'>>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'B','b','B'>>>,::cpp2::regex::group_matcher_end_logic<char,1>>,0,-1,true,true,'*'>,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,2,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::alternative_matcher_logic<char,1,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'A','a','A'>>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'B','b','B'>>>,::cpp2::regex::group_matcher_end_logic<char,2>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_297 {}; public: ::cpp2::regex::regular_expression<char,0,3,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::range_matcher_logic<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'A','a','A'>>,::cpp2::regex::group_matcher_end_logic<char,1>>,1,5,true,true>,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,2,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'A','a','A'>>,::cpp2::regex::group_matcher_end_logic<char,2>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_298 {}; public: ::cpp2::regex::regular_expression<char,0,3,2,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::range_matcher_logic<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::alternative_matcher_logic<char,0,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'A','a','A'>>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'B','b','B'>>>,::cpp2::regex::group_matcher_end_logic<char,1>>,1,5,true,true>,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,2,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::alternative_matcher_logic<char,1,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'A','a','A'>>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'B','b','B'>>>,::cpp2::regex::group_matcher_end_logic<char,2>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_299 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_3 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::range_matcher_logic<char,::cpp2::regex::named_class_no_new_line<char>,1,1,true,false>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_30 {}; public: ::cpp2::regex::regular_expression<char,0,3,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'A','a','A'>>,::cpp2::regex::group_matcher_end_logic<char,1>>,0,1,true,true,'?'>,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,2,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'A','a','A'>>,::cpp2::regex::group_matcher_end_logic<char,2>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_300 {}; public: ::cpp2::regex::regular_expression<char,0,3,2,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::alternative_matcher_logic<char,0,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'A','a','A'>>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'B','b','B'>>>,::cpp2::regex::group_matcher_end_logic<char,1>>,0,1,true,true,'?'>,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,2,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::alternative_matcher_logic<char,1,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'A','a','A'>>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'B','b','B'>>>,::cpp2::regex::group_matcher_end_logic<char,2>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_301 {}; public: ::cpp2::regex::regular_expression<char,0,2,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'A','a','A'>>,::cpp2::regex::group_matcher_end_logic<char,1>>,1,-1,true,true,'+'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_302 {}; public: ::cpp2::regex::regular_expression<char,0,2,1,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::alternative_matcher_logic<char,0,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'A','a','A'>>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'B','b','B'>>>,::cpp2::regex::group_matcher_end_logic<char,1>>,1,-1,true,true,'+'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_303 {}; public: ::cpp2::regex::regular_expression<char,0,2,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'A','a','A'>>,::cpp2::regex::group_matcher_end_logic<char,1>>,0,-1,true,true,'*'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_304 {}; public: ::cpp2::regex::regular_expression<char,0,2,1,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::alternative_matcher_logic<char,0,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'A','a','A'>>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'B','b','B'>>>,::cpp2::regex::group_matcher_end_logic<char,1>>,0,-1,true,true,'*'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_305 {}; public: ::cpp2::regex::regular_expression<char,0,2,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::range_matcher_logic<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'A','a','A'>>,::cpp2::regex::group_matcher_end_logic<char,1>>,1,5,true,true>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_306 {}; public: ::cpp2::regex::regular_expression<char,0,2,1,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::range_matcher_logic<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::alternative_matcher_logic<char,0,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'A','a','A'>>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'B','b','B'>>>,::cpp2::regex::group_matcher_end_logic<char,1>>,1,5,true,true>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_307 {}; public: ::cpp2::regex::regular_expression<char,0,2,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'A','a','A'>>,::cpp2::regex::group_matcher_end_logic<char,1>>,0,1,true,true,'?'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_308 {}; public: ::cpp2::regex::regular_expression<char,0,2,1,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::alternative_matcher_logic<char,0,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'A','a','A'>>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'B','b','B'>>>,::cpp2::regex::group_matcher_end_logic<char,1>>,0,1,true,true,'?'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_309 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::range_matcher_logic<char,::cpp2::regex::named_class_no_new_line<char>,1,1,true,false>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_31 {}; public: ::cpp2::regex::regular_expression<char,0,3,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'f','f','F'>,::cpp2::regex::char_matcher_logic<char,'o','o','O'>,::cpp2::regex::char_matcher_logic<char,'o','o','O'>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'A','a','A'>>,::cpp2::regex::group_matcher_end_logic<char,1>>,1,-1,true,true,'+'>,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,2,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'A','a','A'>>,::cpp2::regex::group_matcher_end_logic<char,2>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_310 {}; public: ::cpp2::regex::regular_expression<char,0,3,2,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'f','f','F'>,::cpp2::regex::char_matcher_logic<char,'o','o','O'>,::cpp2::regex::char_matcher_logic<char,'o','o','O'>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::alternative_matcher_logic<char,0,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'A','a','A'>>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'B','b','B'>>>,::cpp2::regex::group_matcher_end_logic<char,1>>,1,-1,true,true,'+'>,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,2,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::alternative_matcher_logic<char,1,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'A','a','A'>>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'B','b','B'>>>,::cpp2::regex::group_matcher_end_logic<char,2>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_311 {}; public: ::cpp2::regex::regular_expression<char,0,3,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'f','f','F'>,::cpp2::regex::char_matcher_logic<char,'o','o','O'>,::cpp2::regex::char_matcher_logic<char,'o','o','O'>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'A','a','A'>>,::cpp2::regex::group_matcher_end_logic<char,1>>,0,-1,true,true,'*'>,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,2,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'A','a','A'>>,::cpp2::regex::group_matcher_end_logic<char,2>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_312 {}; public: ::cpp2::regex::regular_expression<char,0,3,2,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'f','f','F'>,::cpp2::regex::char_matcher_logic<char,'o','o','O'>,::cpp2::regex::char_matcher_logic<char,'o','o','O'>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::alternative_matcher_logic<char,0,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'A','a','A'>>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'B','b','B'>>>,::cpp2::regex::group_matcher_end_logic<char,1>>,0,-1,true,true,'*'>,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,2,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::alternative_matcher_logic<char,1,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'A','a','A'>>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'B','b','B'>>>,::cpp2::regex::group_matcher_end_logic<char,2>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_313 {}; public: ::cpp2::regex::regular_expression<char,0,3,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'f','f','F'>,::cpp2::regex::char_matcher_logic<char,'o','o','O'>,::cpp2::regex::char_matcher_logic<char,'o','o','O'>,::cpp2::regex::range_matcher_logic<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'A','a','A'>>,::cpp2::regex::group_matcher_end_logic<char,1>>,1,5,true,true>,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,2,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'A','a','A'>>,::cpp2::regex::group_matcher_end_logic<char,2>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_314 {}; public: ::cpp2::regex::regular_expression<char,0,3,2,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'f','f','F'>,::cpp2::regex::char_matcher_logic<char,'o','o','O'>,::cpp2::regex::char_matcher_logic<char,'o','o','O'>,::cpp2::regex::range_matcher_logic<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::alternative_matcher_logic<char,0,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'A','a','A'>>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'B','b','B'>>>,::cpp2::regex::group_matcher_end_logic<char,1>>,1,5,true,true>,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,2,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::alternative_matcher_logic<char,1,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'A','a','A'>>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'B','b','B'>>>,::cpp2::regex::group_matcher_end_logic<char,2>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_315 {}; public: ::cpp2::regex::regular_expression<char,0,3,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'f','f','F'>,::cpp2::regex::char_matcher_logic<char,'o','o','O'>,::cpp2::regex::char_matcher_logic<char,'o','o','O'>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'A','a','A'>>,::cpp2::regex::group_matcher_end_logic<char,1>>,0,1,true,true,'?'>,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,2,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'A','a','A'>>,::cpp2::regex::group_matcher_end_logic<char,2>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_316 {}; public: ::cpp2::regex::regular_expression<char,0,3,2,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'f','f','F'>,::cpp2::regex::char_matcher_logic<char,'o','o','O'>,::cpp2::regex::char_matcher_logic<char,'o','o','O'>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::alternative_matcher_logic<char,0,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'A','a','A'>>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'B','b','B'>>>,::cpp2::regex::group_matcher_end_logic<char,1>>,0,1,true,true,'?'>,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,2,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::alternative_matcher_logic<char,1,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'A','a','A'>>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'B','b','B'>>>,::cpp2::regex::group_matcher_end_logic<char,2>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_317 {}; public: ::cpp2::regex::regular_expression<char,0,2,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'f','f','F'>,::cpp2::regex::char_matcher_logic<char,'o','o','O'>,::cpp2::regex::char_matcher_logic<char,'o','o','O'>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'A','a','A'>>,::cpp2::regex::group_matcher_end_logic<char,1>>,1,-1,true,true,'+'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_318 {}; public: ::cpp2::regex::regular_expression<char,0,2,1,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'f','f','F'>,::cpp2::regex::char_matcher_logic<char,'o','o','O'>,::cpp2::regex::char_matcher_logic<char,'o','o','O'>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::alternative_matcher_logic<char,0,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'A','a','A'>>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'B','b','B'>>>,::cpp2::regex::group_matcher_end_logic<char,1>>,1,-1,true,true,'+'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_319 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::range_matcher_logic<char,::cpp2::regex::named_class_no_new_line<char>,1,1,true,false>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_32 {}; public: ::cpp2::regex::regular_expression<char,0,2,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'f','f','F'>,::cpp2::regex::char_matcher_logic<char,'o','o','O'>,::cpp2::regex::char_matcher_logic<char,'o','o','O'>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'A','a','A'>>,::cpp2::regex::group_matcher_end_logic<char,1>>,0,-1,true,true,'*'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_320 {}; public: ::cpp2::regex::regular_expression<char,0,2,1,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'f','f','F'>,::cpp2::regex::char_matcher_logic<char,'o','o','O'>,::cpp2::regex::char_matcher_logic<char,'o','o','O'>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::alternative_matcher_logic<char,0,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'A','a','A'>>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'B','b','B'>>>,::cpp2::regex::group_matcher_end_logic<char,1>>,0,-1,true,true,'*'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_321 {}; public: ::cpp2::regex::regular_expression<char,0,2,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'f','f','F'>,::cpp2::regex::char_matcher_logic<char,'o','o','O'>,::cpp2::regex::char_matcher_logic<char,'o','o','O'>,::cpp2::regex::range_matcher_logic<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'A','a','A'>>,::cpp2::regex::group_matcher_end_logic<char,1>>,1,5,true,true>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_322 {}; public: ::cpp2::regex::regular_expression<char,0,2,1,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'f','f','F'>,::cpp2::regex::char_matcher_logic<char,'o','o','O'>,::cpp2::regex::char_matcher_logic<char,'o','o','O'>,::cpp2::regex::range_matcher_logic<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::alternative_matcher_logic<char,0,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'A','a','A'>>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'B','b','B'>>>,::cpp2::regex::group_matcher_end_logic<char,1>>,1,5,true,true>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_323 {}; public: ::cpp2::regex::regular_expression<char,0,2,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'f','f','F'>,::cpp2::regex::char_matcher_logic<char,'o','o','O'>,::cpp2::regex::char_matcher_logic<char,'o','o','O'>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'A','a','A'>>,::cpp2::regex::group_matcher_end_logic<char,1>>,0,1,true,true,'?'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_324 {}; public: ::cpp2::regex::regular_expression<char,0,2,1,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'f','f','F'>,::cpp2::regex::char_matcher_logic<char,'o','o','O'>,::cpp2::regex::char_matcher_logic<char,'o','o','O'>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::alternative_matcher_logic<char,0,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'A','a','A'>>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'B','b','B'>>>,::cpp2::regex::group_matcher_end_logic<char,1>>,0,1,true,true,'?'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_325 {}; public: ::cpp2::regex::regular_expression<char,0,2,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'f','f','F'>,::cpp2::regex::char_matcher_logic<char,'o','o','O'>,::cpp2::regex::char_matcher_logic<char,'o','o','O'>,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::named_class_hor_space<char>,1,-1,true,false,'+'>>,::cpp2::regex::group_matcher_end_logic<char,1>>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'r','r','R'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_326 {}; public: ::cpp2::regex::regular_expression<char,0,3,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::named_class_not_hor_space<char>,1,-1,true,false,'+'>>,::cpp2::regex::group_matcher_end_logic<char,1>>,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,2,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::named_class_hor_space<char>>,::cpp2::regex::group_matcher_end_logic<char,2>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_327 {}; public: ::cpp2::regex::regular_expression<char,0,3,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::named_class_hor_space<char>,1,-1,true,false,'+'>>,::cpp2::regex::group_matcher_end_logic<char,1>>,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,2,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::named_class_not_hor_space<char>>,::cpp2::regex::group_matcher_end_logic<char,2>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_328 {}; public: ::cpp2::regex::regular_expression<char,0,2,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'f','f','F'>,::cpp2::regex::char_matcher_logic<char,'o','o','O'>,::cpp2::regex::char_matcher_logic<char,'o','o','O'>,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::named_class_hor_space<char>>,::cpp2::regex::group_matcher_end_logic<char,1>>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'r','r','R'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_329 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::range_matcher_logic<char,::cpp2::regex::named_class_no_new_line<char>,3,4,true,false>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_33 {}; public: ::cpp2::regex::regular_expression<char,0,3,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::named_class_not_hor_space<char>>,::cpp2::regex::group_matcher_end_logic<char,1>>,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,2,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::named_class_hor_space<char>>,::cpp2::regex::group_matcher_end_logic<char,2>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_330 {}; public: ::cpp2::regex::regular_expression<char,0,3,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::named_class_hor_space<char>>,::cpp2::regex::group_matcher_end_logic<char,1>>,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,2,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::named_class_not_hor_space<char>>,::cpp2::regex::group_matcher_end_logic<char,2>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_331 {}; public: ::cpp2::regex::regular_expression<char,0,2,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'f','f','F'>,::cpp2::regex::char_matcher_logic<char,'o','o','O'>,::cpp2::regex::char_matcher_logic<char,'o','o','O'>,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::named_class_ver_space<char>,1,-1,true,false,'+'>>,::cpp2::regex::group_matcher_end_logic<char,1>>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'r','r','R'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_332 {}; public: ::cpp2::regex::regular_expression<char,0,3,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::named_class_not_ver_space<char>,1,-1,true,false,'+'>>,::cpp2::regex::group_matcher_end_logic<char,1>>,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,2,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::named_class_ver_space<char>>,::cpp2::regex::group_matcher_end_logic<char,2>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_333 {}; public: ::cpp2::regex::regular_expression<char,0,3,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::named_class_ver_space<char>,1,-1,true,false,'+'>>,::cpp2::regex::group_matcher_end_logic<char,1>>,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,2,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::named_class_not_ver_space<char>>,::cpp2::regex::group_matcher_end_logic<char,2>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_334 {}; public: ::cpp2::regex::regular_expression<char,0,2,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'f','f','F'>,::cpp2::regex::char_matcher_logic<char,'o','o','O'>,::cpp2::regex::char_matcher_logic<char,'o','o','O'>,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::named_class_ver_space<char>>,::cpp2::regex::group_matcher_end_logic<char,1>>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'r','r','R'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_335 {}; public: ::cpp2::regex::regular_expression<char,0,3,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::named_class_not_ver_space<char>>,::cpp2::regex::group_matcher_end_logic<char,1>>,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,2,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::named_class_ver_space<char>>,::cpp2::regex::group_matcher_end_logic<char,2>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_336 {}; public: ::cpp2::regex::regular_expression<char,0,3,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::named_class_ver_space<char>>,::cpp2::regex::group_matcher_end_logic<char,1>>,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,2,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::named_class_not_ver_space<char>>,::cpp2::regex::group_matcher_end_logic<char,2>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_337 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,-1,::cpp2::regex::match_modifiers_state_change<true,false,0,0,"">,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::modifier_matcher_logic<char,::cpp2::regex::match_modifiers_state_change<true,false,1,0,"i">>,::cpp2::regex::char_matcher_logic<char,'a','a','A'>>,::cpp2::regex::group_matcher_end_logic<char,-1>>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_338 {}; public: ::cpp2::regex::regular_expression<char,0,2,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::modifier_matcher_logic<char,::cpp2::regex::match_modifiers_state_change<true,false,1,0,"i">>,::cpp2::regex::char_matcher_logic<char,'a','a','A'>>,::cpp2::regex::group_matcher_end_logic<char,1>>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_339 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::range_matcher_logic<char,::cpp2::regex::named_class_no_new_line<char>,3,4,true,false>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_34 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,-1,::cpp2::regex::match_modifiers_state_change<true,false,0,0,"">,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::modifier_matcher_logic<char,::cpp2::regex::match_modifiers_state_change<true,false,1,0,"i">>,::cpp2::regex::char_matcher_logic<char,'a','a','A'>>,::cpp2::regex::group_matcher_end_logic<char,-1>>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_340 {}; public: ::cpp2::regex::regular_expression<char,0,2,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::modifier_matcher_logic<char,::cpp2::regex::match_modifiers_state_change<true,false,1,0,"i">>,::cpp2::regex::char_matcher_logic<char,'a','a','A'>>,::cpp2::regex::group_matcher_end_logic<char,1>>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_341 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,-1,::cpp2::regex::match_modifiers_state_change<true,false,0,0,"">,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::modifier_matcher_logic<char,::cpp2::regex::match_modifiers_state_change<true,false,1,0,"i">>,::cpp2::regex::char_matcher_logic<char,'a','a','A'>>,::cpp2::regex::group_matcher_end_logic<char,-1>>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_342 {}; public: ::cpp2::regex::regular_expression<char,0,2,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::modifier_matcher_logic<char,::cpp2::regex::match_modifiers_state_change<true,false,1,0,"i">>,::cpp2::regex::char_matcher_logic<char,'a','a','A'>>,::cpp2::regex::group_matcher_end_logic<char,1>>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_343 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,-1,::cpp2::regex::match_modifiers_state_change<true,false,1,0,"i">,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>>,::cpp2::regex::group_matcher_end_logic<char,-1>>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_344 {}; public: ::cpp2::regex::regular_expression<char,0,2,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,-1,::cpp2::regex::match_modifiers_state_change<true,false,1,0,"i">,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>>,::cpp2::regex::group_matcher_end_logic<char,-1>>>,::cpp2::regex::group_matcher_end_logic<char,1>>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_345 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,-1,::cpp2::regex::match_modifiers_state_change<true,false,1,0,"i">,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>>,::cpp2::regex::group_matcher_end_logic<char,-1>>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_346 {}; public: ::cpp2::regex::regular_expression<char,0,2,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,-1,::cpp2::regex::match_modifiers_state_change<true,false,1,0,"i">,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>>,::cpp2::regex::group_matcher_end_logic<char,-1>>>,::cpp2::regex::group_matcher_end_logic<char,1>>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_347 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,-1,::cpp2::regex::match_modifiers_state_change<true,false,1,0,"i">,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>>,::cpp2::regex::group_matcher_end_logic<char,-1>>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_348 {}; public: ::cpp2::regex::regular_expression<char,0,2,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,-1,::cpp2::regex::match_modifiers_state_change<true,false,1,0,"i">,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>>,::cpp2::regex::group_matcher_end_logic<char,-1>>>,::cpp2::regex::group_matcher_end_logic<char,1>>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_349 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::range_matcher_logic<char,::cpp2::regex::named_class_no_new_line<char>,3,4,true,false>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_35 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,-1,::cpp2::regex::match_modifiers_state_change<true,false,0,0,"">,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::modifier_matcher_logic<char,::cpp2::regex::match_modifiers_state_change<true,false,0,1,"-i">>,::cpp2::regex::char_matcher_logic<char,'a','a','A'>>,::cpp2::regex::group_matcher_end_logic<char,-1>>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_350 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,2,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::modifier_matcher_logic<char,::cpp2::regex::match_modifiers_state_change<true,false,0,1,"-i">>,::cpp2::regex::char_matcher_logic<char,'a','a','A'>>,::cpp2::regex::group_matcher_end_logic<char,1>>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_351 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,-1,::cpp2::regex::match_modifiers_state_change<true,false,0,0,"">,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::modifier_matcher_logic<char,::cpp2::regex::match_modifiers_state_change<true,false,0,1,"-i">>,::cpp2::regex::char_matcher_logic<char,'a','a','A'>>,::cpp2::regex::group_matcher_end_logic<char,-1>>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_352 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,2,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::modifier_matcher_logic<char,::cpp2::regex::match_modifiers_state_change<true,false,0,1,"-i">>,::cpp2::regex::char_matcher_logic<char,'a','a','A'>>,::cpp2::regex::group_matcher_end_logic<char,1>>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_353 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,-1,::cpp2::regex::match_modifiers_state_change<true,false,0,0,"">,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::modifier_matcher_logic<char,::cpp2::regex::match_modifiers_state_change<true,false,0,1,"-i">>,::cpp2::regex::char_matcher_logic<char,'a','a','A'>>,::cpp2::regex::group_matcher_end_logic<char,-1>>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_354 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,2,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::modifier_matcher_logic<char,::cpp2::regex::match_modifiers_state_change<true,false,0,1,"-i">>,::cpp2::regex::char_matcher_logic<char,'a','a','A'>>,::cpp2::regex::group_matcher_end_logic<char,1>>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_355 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,-1,::cpp2::regex::match_modifiers_state_change<true,false,0,0,"">,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::modifier_matcher_logic<char,::cpp2::regex::match_modifiers_state_change<true,false,0,1,"-i">>,::cpp2::regex::char_matcher_logic<char,'a','a','A'>>,::cpp2::regex::group_matcher_end_logic<char,-1>>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_356 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,2,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::modifier_matcher_logic<char,::cpp2::regex::match_modifiers_state_change<true,false,0,1,"-i">>,::cpp2::regex::char_matcher_logic<char,'a','a','A'>>,::cpp2::regex::group_matcher_end_logic<char,1>>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_357 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,-1,::cpp2::regex::match_modifiers_state_change<true,false,0,0,"">,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::modifier_matcher_logic<char,::cpp2::regex::match_modifiers_state_change<true,false,0,1,"-i">>,::cpp2::regex::char_matcher_logic<char,'a','a','A'>>,::cpp2::regex::group_matcher_end_logic<char,-1>>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_358 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,2,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::modifier_matcher_logic<char,::cpp2::regex::match_modifiers_state_change<true,false,0,1,"-i">>,::cpp2::regex::char_matcher_logic<char,'a','a','A'>>,::cpp2::regex::group_matcher_end_logic<char,1>>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_359 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::range_matcher_logic<char,::cpp2::regex::named_class_no_new_line<char>,3,4,true,false>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_36 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,-1,::cpp2::regex::match_modifiers_state_change<true,false,0,1,"-i">,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>>,::cpp2::regex::group_matcher_end_logic<char,-1>>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_360 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,2,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,-1,::cpp2::regex::match_modifiers_state_change<true,false,0,1,"-i">,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>>,::cpp2::regex::group_matcher_end_logic<char,-1>>>,::cpp2::regex::group_matcher_end_logic<char,1>>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_361 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,-1,::cpp2::regex::match_modifiers_state_change<true,false,0,1,"-i">,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>>,::cpp2::regex::group_matcher_end_logic<char,-1>>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_362 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,2,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,-1,::cpp2::regex::match_modifiers_state_change<true,false,0,1,"-i">,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>>,::cpp2::regex::group_matcher_end_logic<char,-1>>>,::cpp2::regex::group_matcher_end_logic<char,1>>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_363 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,-1,::cpp2::regex::match_modifiers_state_change<true,false,0,1,"-i">,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>>,::cpp2::regex::group_matcher_end_logic<char,-1>>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_364 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,2,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,-1,::cpp2::regex::match_modifiers_state_change<true,false,0,1,"-i">,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>>,::cpp2::regex::group_matcher_end_logic<char,-1>>>,::cpp2::regex::group_matcher_end_logic<char,1>>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_365 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,-1,::cpp2::regex::match_modifiers_state_change<true,false,0,1,"-i">,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>>,::cpp2::regex::group_matcher_end_logic<char,-1>>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_366 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,2,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,-1,::cpp2::regex::match_modifiers_state_change<true,false,0,1,"-i">,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>>,::cpp2::regex::group_matcher_end_logic<char,-1>>>,::cpp2::regex::group_matcher_end_logic<char,1>>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_367 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,-1,::cpp2::regex::match_modifiers_state_change<true,false,0,1,"-i">,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>>,::cpp2::regex::group_matcher_end_logic<char,-1>>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_368 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,2,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,-1,::cpp2::regex::match_modifiers_state_change<true,false,0,1,"-i">,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>>,::cpp2::regex::group_matcher_end_logic<char,-1>>>,::cpp2::regex::group_matcher_end_logic<char,1>>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_369 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,0,-1,true,false>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_37 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,2,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,-1,::cpp2::regex::match_modifiers_state_change<true,false,0,1,"-i">,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::any_matcher_logic<char>>,::cpp2::regex::group_matcher_end_logic<char,-1>>>,::cpp2::regex::group_matcher_end_logic<char,1>>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_370 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,2,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,-1,::cpp2::regex::match_modifiers_state_change<true,false,0,1,"-i">,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::named_class_no_new_line<char>>,::cpp2::regex::group_matcher_end_logic<char,-1>>>,::cpp2::regex::group_matcher_end_logic<char,1>>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_371 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,2,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,-1,::cpp2::regex::match_modifiers_state_change<true,false,4,1,"s-i">,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::any_matcher_logic<char>>,::cpp2::regex::group_matcher_end_logic<char,-1>>>,::cpp2::regex::group_matcher_end_logic<char,1>>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_372 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,2,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,-1,::cpp2::regex::match_modifiers_state_change<true,false,4,1,"s-i">,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::named_class_no_new_line<char>>,::cpp2::regex::group_matcher_end_logic<char,-1>>>,::cpp2::regex::group_matcher_end_logic<char,1>>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_373 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,2,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,-1,::cpp2::regex::match_modifiers_state_change<true,false,4,1,"s-i">,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::any_matcher_logic<char>>,::cpp2::regex::group_matcher_end_logic<char,-1>>>,::cpp2::regex::group_matcher_end_logic<char,1>>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_374 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,2,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,-1,::cpp2::regex::match_modifiers_state_change<true,false,4,1,"s-i">,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::named_class_no_new_line<char>>,::cpp2::regex::group_matcher_end_logic<char,-1>>>,::cpp2::regex::group_matcher_end_logic<char,1>>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_375 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::line_start_matcher_logic<char,true>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,-1,::cpp2::regex::match_modifiers_state_change<true,false,0,0,"">,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,0,1,true,false,'?'>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,0,1,true,false,'?'>>,::cpp2::regex::group_matcher_end_logic<char,-1>>,0,-1,true,false,'*'>,::cpp2::regex::line_end_matcher_logic<char,true,true>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_376 {}; public: ::cpp2::regex::regular_expression<char,0,4,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::modifier_matcher_logic<char,::cpp2::regex::match_modifiers_state_change<true,false,4,0,"s">>,::cpp2::regex::line_start_matcher_logic<char,true>,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,2,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::any_matcher_logic<char>>,::cpp2::regex::group_matcher_end_logic<char,2>>>,::cpp2::regex::group_matcher_end_logic<char,1>>,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,3,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::modifier_matcher_logic<char,::cpp2::regex::match_modifiers_state_change<true,false,2,0,"m">>,::cpp2::regex::line_start_matcher_logic<char,true>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::line_end_matcher_logic<char,true,true>>,::cpp2::regex::group_matcher_end_logic<char,3>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_377 {}; public: ::cpp2::regex::regular_expression<char,0,2,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::modifier_matcher_logic<char,::cpp2::regex::match_modifiers_state_change<true,false,2,0,"m">>,::cpp2::regex::line_start_matcher_logic<char,true>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::line_end_matcher_logic<char,true,true>>,::cpp2::regex::group_matcher_end_logic<char,1>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_378 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::modifier_matcher_logic<char,::cpp2::regex::match_modifiers_state_change<true,false,2,0,"m">>,::cpp2::regex::line_start_matcher_logic<char,true>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_379 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,0,-1,true,false>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_38 {}; public: ::cpp2::regex::regular_expression<char,0,2,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::modifier_matcher_logic<char,::cpp2::regex::match_modifiers_state_change<true,false,2,0,"m">>,::cpp2::regex::line_start_matcher_logic<char,true>,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>>,::cpp2::regex::group_matcher_end_logic<char,1>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_380 {}; public: ::cpp2::regex::regular_expression<char,0,2,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::modifier_matcher_logic<char,::cpp2::regex::match_modifiers_state_change<true,false,2,0,"m">>,::cpp2::regex::line_start_matcher_logic<char,true>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>>,::cpp2::regex::group_matcher_end_logic<char,1>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_381 {}; public: ::cpp2::regex::regular_expression<char,0,2,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::special_syntax_wrapper<char,"\\n",::cpp2::regex::char_matcher_logic<char,'\n','\n','\n'>>,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::modifier_matcher_logic<char,::cpp2::regex::match_modifiers_state_change<true,false,2,0,"m">>,::cpp2::regex::line_start_matcher_logic<char,true>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>>,::cpp2::regex::group_matcher_end_logic<char,1>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_382 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::line_start_matcher_logic<char,true>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_383 {}; public: ::cpp2::regex::regular_expression<char,0,2,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char>,::cpp2::regex::group_matcher_end_logic<char,1>>,::cpp2::regex::line_start_matcher_logic<char,true>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_384 {}; public: ::cpp2::regex::regular_expression<char,0,2,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::modifier_matcher_logic<char,::cpp2::regex::match_modifiers_state_change<true,false,2,0,"m">>,::cpp2::regex::line_start_matcher_logic<char,true>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>>,::cpp2::regex::group_matcher_end_logic<char,1>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_385 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::named_string_end_or_before_new_line_at_end<char>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_386 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::named_string_end<char>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_387 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::line_end_matcher_logic<char,true,true>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_388 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::named_string_end_or_before_new_line_at_end<char>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_389 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,0,-1,true,false>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_39 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::named_string_end<char>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_390 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::line_end_matcher_logic<char,true,true>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_391 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::named_string_end_or_before_new_line_at_end<char>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_392 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::named_string_end<char>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_393 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::line_end_matcher_logic<char,true,true>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_394 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::multiple_lines,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::named_string_end_or_before_new_line_at_end<char>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_395 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::multiple_lines,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::named_string_end<char>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_396 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::multiple_lines,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::line_end_matcher_logic<char,true,true>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_397 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::multiple_lines,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::named_string_end_or_before_new_line_at_end<char>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_398 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::multiple_lines,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::named_string_end<char>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_399 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_4 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,1,-1,true,false,'+'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_40 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::multiple_lines,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::line_end_matcher_logic<char,true,true>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_400 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::multiple_lines,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::named_string_end_or_before_new_line_at_end<char>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_401 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::multiple_lines,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::named_string_end<char>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_402 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::multiple_lines,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::line_end_matcher_logic<char,true,true>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_403 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::named_string_end_or_before_new_line_at_end<char>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_404 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::named_string_end<char>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_405 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::line_end_matcher_logic<char,true,true>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_406 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::named_string_end_or_before_new_line_at_end<char>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_407 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::named_string_end<char>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_408 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::line_end_matcher_logic<char,true,true>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_409 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,1,-1,true,false,'+'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_41 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::named_string_end_or_before_new_line_at_end<char>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_410 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::named_string_end<char>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_411 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::line_end_matcher_logic<char,true,true>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_412 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::multiple_lines,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::named_string_end_or_before_new_line_at_end<char>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_413 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::multiple_lines,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::named_string_end<char>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_414 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::multiple_lines,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::line_end_matcher_logic<char,true,true>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_415 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::multiple_lines,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::named_string_end_or_before_new_line_at_end<char>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_416 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::multiple_lines,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::named_string_end<char>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_417 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::multiple_lines,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::line_end_matcher_logic<char,true,true>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_418 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::multiple_lines,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::named_string_end_or_before_new_line_at_end<char>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_419 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,1,-1,true,false,'+'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_42 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::multiple_lines,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::named_string_end<char>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_420 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::multiple_lines,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::line_end_matcher_logic<char,true,true>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_421 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::named_string_end_or_before_new_line_at_end<char>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_422 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::named_string_end<char>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_423 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::line_end_matcher_logic<char,true,true>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_424 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::named_string_end_or_before_new_line_at_end<char>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_425 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::named_string_end<char>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_426 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::line_end_matcher_logic<char,true,true>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_427 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::named_string_end_or_before_new_line_at_end<char>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_428 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::named_string_end<char>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_429 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,1,-1,true,false,'+'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_43 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::line_end_matcher_logic<char,true,true>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_430 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::multiple_lines,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::named_string_end_or_before_new_line_at_end<char>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_431 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::multiple_lines,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::named_string_end<char>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_432 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::multiple_lines,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::line_end_matcher_logic<char,true,true>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_433 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::multiple_lines,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::named_string_end_or_before_new_line_at_end<char>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_434 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::multiple_lines,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::named_string_end<char>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_435 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::multiple_lines,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::line_end_matcher_logic<char,true,true>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_436 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::multiple_lines,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::named_string_end_or_before_new_line_at_end<char>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_437 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::multiple_lines,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::named_string_end<char>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_438 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::multiple_lines,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::line_end_matcher_logic<char,true,true>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_439 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,1,-1,true,false,'+'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_44 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::named_string_end_or_before_new_line_at_end<char>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_440 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::named_string_end<char>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_441 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::line_end_matcher_logic<char,true,true>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_442 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::named_string_end_or_before_new_line_at_end<char>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_443 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::named_string_end<char>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_444 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::line_end_matcher_logic<char,true,true>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_445 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::named_string_end_or_before_new_line_at_end<char>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_446 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::named_string_end<char>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_447 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::line_end_matcher_logic<char,true,true>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_448 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::multiple_lines,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::named_string_end_or_before_new_line_at_end<char>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_449 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,1,-1,true,false>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_45 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::multiple_lines,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::named_string_end<char>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_450 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::multiple_lines,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::line_end_matcher_logic<char,true,true>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_451 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::multiple_lines,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::named_string_end_or_before_new_line_at_end<char>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_452 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::multiple_lines,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::named_string_end<char>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_453 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::multiple_lines,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::line_end_matcher_logic<char,true,true>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_454 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::multiple_lines,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::named_string_end_or_before_new_line_at_end<char>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_455 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::multiple_lines,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::named_string_end<char>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_456 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::multiple_lines,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::line_end_matcher_logic<char,true,true>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_457 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::named_string_end_or_before_new_line_at_end<char>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_458 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::named_string_end<char>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_459 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,1,-1,true,false,'+'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_46 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::line_end_matcher_logic<char,true,true>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_460 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::named_string_end_or_before_new_line_at_end<char>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_461 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::named_string_end<char>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_462 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::line_end_matcher_logic<char,true,true>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_463 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::named_string_end_or_before_new_line_at_end<char>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_464 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::named_string_end<char>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_465 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::line_end_matcher_logic<char,true,true>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_466 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::multiple_lines,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::named_string_end_or_before_new_line_at_end<char>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_467 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::multiple_lines,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::named_string_end<char>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_468 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::multiple_lines,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::line_end_matcher_logic<char,true,true>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_469 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,1,-1,true,false,'+'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_47 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::multiple_lines,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::named_string_end_or_before_new_line_at_end<char>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_470 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::multiple_lines,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::named_string_end<char>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_471 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::multiple_lines,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::line_end_matcher_logic<char,true,true>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_472 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::multiple_lines,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::named_string_end_or_before_new_line_at_end<char>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_473 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::multiple_lines,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::named_string_end<char>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_474 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::multiple_lines,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::line_end_matcher_logic<char,true,true>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_475 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::named_string_end_or_before_new_line_at_end<char>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_476 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::named_string_end<char>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_477 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::line_end_matcher_logic<char,true,true>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_478 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::named_string_end_or_before_new_line_at_end<char>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_479 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,1,-1,true,false,'+'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_48 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::named_string_end<char>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_480 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::line_end_matcher_logic<char,true,true>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_481 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::named_string_end_or_before_new_line_at_end<char>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_482 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::named_string_end<char>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_483 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::line_end_matcher_logic<char,true,true>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_484 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::multiple_lines,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::named_string_end_or_before_new_line_at_end<char>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_485 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::multiple_lines,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::named_string_end<char>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_486 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::multiple_lines,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::line_end_matcher_logic<char,true,true>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_487 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::multiple_lines,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::named_string_end_or_before_new_line_at_end<char>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_488 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::multiple_lines,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::named_string_end<char>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_489 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,1,-1,true,false>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_49 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::multiple_lines,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::line_end_matcher_logic<char,true,true>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_490 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::multiple_lines,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::named_string_end_or_before_new_line_at_end<char>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_491 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::multiple_lines,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::named_string_end<char>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_492 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::multiple_lines,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::line_end_matcher_logic<char,true,true>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_493 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::named_string_end_or_before_new_line_at_end<char>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_494 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::named_string_end<char>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_495 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::line_end_matcher_logic<char,true,true>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_496 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::named_string_end_or_before_new_line_at_end<char>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_497 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::named_string_end<char>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_498 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::line_end_matcher_logic<char,true,true>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_499 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_5 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,1,-1,true,false>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_50 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::named_string_end_or_before_new_line_at_end<char>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_500 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::named_string_end<char>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_501 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::line_end_matcher_logic<char,true,true>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_502 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::multiple_lines,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::named_string_end_or_before_new_line_at_end<char>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_503 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::multiple_lines,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::named_string_end<char>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_504 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::multiple_lines,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::line_end_matcher_logic<char,true,true>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_505 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::multiple_lines,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::named_string_end_or_before_new_line_at_end<char>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_506 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::multiple_lines,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::named_string_end<char>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_507 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::multiple_lines,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::line_end_matcher_logic<char,true,true>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_508 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::multiple_lines,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::named_string_end_or_before_new_line_at_end<char>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_509 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,1,-1,true,false>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_51 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::multiple_lines,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::named_string_end<char>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_510 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::multiple_lines,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::line_end_matcher_logic<char,true,true>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_511 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::named_string_end_or_before_new_line_at_end<char>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_512 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::named_string_end<char>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_513 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::line_end_matcher_logic<char,true,true>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_514 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::named_string_end_or_before_new_line_at_end<char>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_515 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::named_string_end<char>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_516 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::line_end_matcher_logic<char,true,true>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_517 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::named_string_end_or_before_new_line_at_end<char>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_518 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::named_string_end<char>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_519 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,1,3,true,false>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_52 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::line_end_matcher_logic<char,true,true>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_520 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::multiple_lines,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::named_string_end_or_before_new_line_at_end<char>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_521 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::multiple_lines,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::named_string_end<char>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_522 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::multiple_lines,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::line_end_matcher_logic<char,true,true>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_523 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::multiple_lines,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::named_string_end_or_before_new_line_at_end<char>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_524 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::multiple_lines,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::named_string_end<char>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_525 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::multiple_lines,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::line_end_matcher_logic<char,true,true>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_526 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::multiple_lines,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::named_string_end_or_before_new_line_at_end<char>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_527 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::multiple_lines,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::named_string_end<char>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_528 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::multiple_lines,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::line_end_matcher_logic<char,true,true>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_529 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,1,3,true,false>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_53 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::named_string_end_or_before_new_line_at_end<char>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_530 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::named_string_end<char>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_531 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::line_end_matcher_logic<char,true,true>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_532 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::named_string_end_or_before_new_line_at_end<char>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_533 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::named_string_end<char>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_534 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::line_end_matcher_logic<char,true,true>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_535 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::named_string_end_or_before_new_line_at_end<char>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_536 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::named_string_end<char>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_537 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::line_end_matcher_logic<char,true,true>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_538 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::multiple_lines,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::named_string_end_or_before_new_line_at_end<char>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_539 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,1,3,true,false>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_54 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::multiple_lines,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::named_string_end<char>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_540 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::multiple_lines,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::line_end_matcher_logic<char,true,true>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_541 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::multiple_lines,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::named_string_end_or_before_new_line_at_end<char>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_542 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::multiple_lines,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::named_string_end<char>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_543 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::multiple_lines,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::line_end_matcher_logic<char,true,true>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_544 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::multiple_lines,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::named_string_end_or_before_new_line_at_end<char>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_545 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::multiple_lines,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::named_string_end<char>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_546 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::multiple_lines,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::line_end_matcher_logic<char,true,true>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_547 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::named_string_end_or_before_new_line_at_end<char>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_548 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::named_string_end<char>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_549 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,3,4,true,false>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_55 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::line_end_matcher_logic<char,true,true>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_550 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::named_string_end_or_before_new_line_at_end<char>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_551 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::named_string_end<char>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_552 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::line_end_matcher_logic<char,true,true>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_553 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::named_string_end_or_before_new_line_at_end<char>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_554 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::named_string_end<char>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_555 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::line_end_matcher_logic<char,true,true>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_556 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::multiple_lines,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::named_string_end_or_before_new_line_at_end<char>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_557 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::multiple_lines,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::named_string_end<char>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_558 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::multiple_lines,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::line_end_matcher_logic<char,true,true>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_559 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,3,4,true,false>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_56 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::multiple_lines,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::named_string_end_or_before_new_line_at_end<char>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_560 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::multiple_lines,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::named_string_end<char>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_561 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::multiple_lines,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::line_end_matcher_logic<char,true,true>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_562 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::multiple_lines,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::named_string_end_or_before_new_line_at_end<char>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_563 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::multiple_lines,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::named_string_end<char>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_564 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::multiple_lines,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::line_end_matcher_logic<char,true,true>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_565 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::named_string_end_or_before_new_line_at_end<char>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_566 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::named_string_end<char>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_567 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::line_end_matcher_logic<char,true,true>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_568 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::named_string_end_or_before_new_line_at_end<char>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_569 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,3,4,true,false>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_57 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::named_string_end<char>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_570 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::line_end_matcher_logic<char,true,true>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_571 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::named_string_end_or_before_new_line_at_end<char>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_572 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::named_string_end<char>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_573 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::line_end_matcher_logic<char,true,true>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_574 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::multiple_lines,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::named_string_end_or_before_new_line_at_end<char>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_575 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::multiple_lines,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::named_string_end<char>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_576 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::multiple_lines,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::line_end_matcher_logic<char,true,true>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_577 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::multiple_lines,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::named_string_end_or_before_new_line_at_end<char>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_578 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::multiple_lines,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::named_string_end<char>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_579 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,4,5,true,false>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_58 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::multiple_lines,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::line_end_matcher_logic<char,true,true>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_580 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::multiple_lines,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::named_string_end_or_before_new_line_at_end<char>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_581 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::multiple_lines,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::named_string_end<char>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_582 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::multiple_lines,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::line_end_matcher_logic<char,true,true>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_583 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::multiple_lines,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::named_string_start<char>,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::line_end_matcher_logic<char,true,true>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_584 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,-1,::cpp2::regex::match_modifiers_state_change<true,false,1,0,"i">,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::any_matcher_logic<char>,::cpp2::regex::class_matcher_logic<char,false,::cpp2::regex::single_class_entry<char,'b'>>,::cpp2::regex::any_matcher_logic<char>>,::cpp2::regex::group_matcher_end_logic<char,-1>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_585 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,-1,::cpp2::regex::match_modifiers_state_change<true,false,1,0,"i">,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::named_class_no_new_line<char>,::cpp2::regex::class_matcher_logic<char,false,::cpp2::regex::single_class_entry<char,'b'>>,::cpp2::regex::named_class_no_new_line<char>>,::cpp2::regex::group_matcher_end_logic<char,-1>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_586 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::perl_code_syntax,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::range_matcher_logic<char,::cpp2::regex::named_class_no_new_line<char>,1,1,true,false>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_587 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::perl_code_syntax,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::range_matcher_logic<char,::cpp2::regex::named_class_no_new_line<char>,1,1,true,false>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_588 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::perl_code_syntax,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::range_matcher_logic<char,::cpp2::regex::named_class_no_new_line<char>,1,1,true,false>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_589 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,0,1,true,false,'?'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_59 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::perl_code_syntax,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::range_matcher_logic<char,::cpp2::regex::named_class_no_new_line<char>,3,4,true,false>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_590 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::perl_code_syntax,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::range_matcher_logic<char,::cpp2::regex::named_class_no_new_line<char>,3,4,true,false>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_591 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::perl_code_syntax,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::range_matcher_logic<char,::cpp2::regex::named_class_no_new_line<char>,3,4,true,false>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_592 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::perl_code_syntax,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::named_class_no_new_line<char>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_593 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::perl_code_syntax,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::named_class_no_new_line<char>,0,-1,true,false,'*'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_594 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::perl_code_syntax,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::named_class_no_new_line<char>,0,-1,true,false,'*'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_595 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::perl_code_syntax,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::class_matcher_logic<char,false,::cpp2::regex::single_class_entry<char,'a'>,::cpp2::regex::single_class_entry<char,' '>,::cpp2::regex::single_class_entry<char,'b'>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_596 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::perl_code_syntax | ::cpp2::regex::expression_flags::perl_code_syntax_in_classes,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::class_matcher_logic<char,false,::cpp2::regex::single_class_entry<char,'a'>,::cpp2::regex::single_class_entry<char,'b'>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_597 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::perl_code_syntax | ::cpp2::regex::expression_flags::perl_code_syntax_in_classes,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::class_matcher_logic<char,false,::cpp2::regex::single_class_entry<char,'a'>,::cpp2::regex::single_class_entry<char,' '>,::cpp2::regex::single_class_entry<char,'b'>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_598 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::perl_code_syntax | ::cpp2::regex::expression_flags::perl_code_syntax_in_classes,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::class_matcher_logic<char,true,::cpp2::regex::single_class_entry<char,'a'>,::cpp2::regex::single_class_entry<char,'b'>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_599 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_6 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,0,1,true,false,'?'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_60 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::perl_code_syntax | ::cpp2::regex::expression_flags::perl_code_syntax_in_classes,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::class_matcher_logic<char,true,::cpp2::regex::single_class_entry<char,'a'>,::cpp2::regex::single_class_entry<char,'b'>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_600 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::perl_code_syntax | ::cpp2::regex::expression_flags::perl_code_syntax_in_classes,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::class_matcher_logic<char,true,::cpp2::regex::single_class_entry<char,'a'>,::cpp2::regex::single_class_entry<char,'b'>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_601 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::perl_code_syntax | ::cpp2::regex::expression_flags::perl_code_syntax_in_classes,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,-1,::cpp2::regex::match_modifiers_state_change<true,false,16,32,"x">,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::class_matcher_logic<char,false,::cpp2::regex::single_class_entry<char,'a'>,::cpp2::regex::single_class_entry<char,' '>,::cpp2::regex::single_class_entry<char,'b'>>>,::cpp2::regex::group_matcher_end_logic<char,-1>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_602 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::perl_code_syntax,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,-1,::cpp2::regex::match_modifiers_state_change<true,false,48,0,"xx">,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::class_matcher_logic<char,false,::cpp2::regex::single_class_entry<char,'a'>,::cpp2::regex::single_class_entry<char,'b'>>>,::cpp2::regex::group_matcher_end_logic<char,-1>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_603 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::perl_code_syntax | ::cpp2::regex::expression_flags::perl_code_syntax_in_classes,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::modifier_matcher_logic<char,::cpp2::regex::match_modifiers_state_change<true,false,16,32,"x">>,::cpp2::regex::class_matcher_logic<char,false,::cpp2::regex::single_class_entry<char,'a'>,::cpp2::regex::single_class_entry<char,' '>,::cpp2::regex::single_class_entry<char,'b'>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_604 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::perl_code_syntax,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::modifier_matcher_logic<char,::cpp2::regex::match_modifiers_state_change<true,false,48,0,"xx">>,::cpp2::regex::class_matcher_logic<char,false,::cpp2::regex::single_class_entry<char,'a'>,::cpp2::regex::single_class_entry<char,'b'>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_605 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::perl_code_syntax | ::cpp2::regex::expression_flags::perl_code_syntax_in_classes,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,-1,::cpp2::regex::match_modifiers_state_change<true,false,0,48,"-x">,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::class_matcher_logic<char,false,::cpp2::regex::single_class_entry<char,'a'>,::cpp2::regex::single_class_entry<char,' '>,::cpp2::regex::single_class_entry<char,'b'>>>,::cpp2::regex::group_matcher_end_logic<char,-1>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_606 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::perl_code_syntax,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::range_matcher_logic<char,::cpp2::regex::named_class_no_new_line<char>,1,1,true,false>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_607 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::perl_code_syntax,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::range_matcher_logic<char,::cpp2::regex::named_class_no_new_line<char>,1,1,true,false>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_608 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::perl_code_syntax,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::range_matcher_logic<char,::cpp2::regex::named_class_no_new_line<char>,1,1,true,false>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_609 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,0,1,true,false>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_61 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::perl_code_syntax,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::range_matcher_logic<char,::cpp2::regex::named_class_no_new_line<char>,3,4,true,false>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_610 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::perl_code_syntax,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::range_matcher_logic<char,::cpp2::regex::named_class_no_new_line<char>,3,4,true,false>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_611 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::perl_code_syntax,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::range_matcher_logic<char,::cpp2::regex::named_class_no_new_line<char>,3,4,true,false>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_612 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::perl_code_syntax,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::named_class_no_new_line<char>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_613 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::perl_code_syntax,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::named_class_no_new_line<char>,0,-1,true,false,'*'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_614 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::perl_code_syntax,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::named_class_no_new_line<char>,0,-1,true,false,'*'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_615 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::class_matcher_logic<char,false,::cpp2::regex::single_class_entry<char,'#'>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_616 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::class_matcher_logic<char,false,::cpp2::regex::single_class_entry<char,'#'>>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_617 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::perl_code_syntax,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::class_matcher_logic<char,false,::cpp2::regex::single_class_entry<char,'#'>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_618 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::perl_code_syntax,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::class_matcher_logic<char,false,::cpp2::regex::single_class_entry<char,'#'>>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_619 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,0,1,true,false,'?'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_62 {}; public: ::cpp2::regex::regular_expression<char,0,2,0,::cpp2::regex::group_name_list<"n",1,::cpp2::regex::group_name_list_end>,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"n",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'f','f','F'>,::cpp2::regex::char_matcher_logic<char,'o','o','O'>,::cpp2::regex::char_matcher_logic<char,'o','o','O'>>,::cpp2::regex::group_matcher_end_logic<char,1>>,::cpp2::regex::char_matcher_logic<char,' ',' ',' '>,::cpp2::regex::group_ref_matcher_logic<char,1,"\\g{n}">>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_620 {}; public: ::cpp2::regex::regular_expression<char,0,2,0,::cpp2::regex::group_name_list<"n",1,::cpp2::regex::group_name_list_end>,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"n",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'f','f','F'>,::cpp2::regex::char_matcher_logic<char,'o','o','O'>,::cpp2::regex::char_matcher_logic<char,'o','o','O'>>,::cpp2::regex::group_matcher_end_logic<char,1>>,::cpp2::regex::char_matcher_logic<char,' ',' ',' '>,::cpp2::regex::group_ref_matcher_logic<char,1,"\\g{ n }">>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_621 {}; public: ::cpp2::regex::regular_expression<char,0,2,0,::cpp2::regex::group_name_list<"n",1,::cpp2::regex::group_name_list_end>,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"n",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'f','f','F'>,::cpp2::regex::char_matcher_logic<char,'o','o','O'>,::cpp2::regex::char_matcher_logic<char,'o','o','O'>>,::cpp2::regex::group_matcher_end_logic<char,1>>,::cpp2::regex::char_matcher_logic<char,' ',' ',' '>,::cpp2::regex::group_ref_matcher_logic<char,1,"\\g{n}">>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_622 {}; public: ::cpp2::regex::regular_expression<char,0,2,0,::cpp2::regex::group_name_list<"n",1,::cpp2::regex::group_name_list_end>,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"n",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'f','f','F'>,::cpp2::regex::char_matcher_logic<char,'o','o','O'>,::cpp2::regex::char_matcher_logic<char,'o','o','O'>>,::cpp2::regex::group_matcher_end_logic<char,1>>,::cpp2::regex::char_matcher_logic<char,' ',' ',' '>,::cpp2::regex::group_ref_matcher_logic<char,1,"\\g{n}">>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_623 {}; public: ::cpp2::regex::regular_expression<char,0,2,0,::cpp2::regex::group_name_list<"n",1,::cpp2::regex::group_name_list_end>,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"n",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'f','f','F'>,::cpp2::regex::char_matcher_logic<char,'o','o','O'>,::cpp2::regex::char_matcher_logic<char,'o','o','O'>>,::cpp2::regex::group_matcher_end_logic<char,1>>,::cpp2::regex::char_matcher_logic<char,' ',' ',' '>,::cpp2::regex::group_ref_matcher_logic<char,1,"\\g{n}">>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_624 {}; public: ::cpp2::regex::regular_expression<char,0,4,0,::cpp2::regex::group_name_list<"as",1,::cpp2::regex::group_name_list_end>,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"as",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'s','s','S'>>,::cpp2::regex::group_matcher_end_logic<char,1>>,::cpp2::regex::char_matcher_logic<char,' ',' ',' '>,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,2,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::named_class_word<char>,1,-1,true,false,'+'>>,::cpp2::regex::group_matcher_end_logic<char,2>>,::cpp2::regex::char_matcher_logic<char,' ',' ',' '>,::cpp2::regex::group_ref_matcher_logic<char,1,"\\g{as}">,::cpp2::regex::char_matcher_logic<char,' ',' ',' '>,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,3,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::named_class_word<char>,1,-1,true,false,'+'>>,::cpp2::regex::group_matcher_end_logic<char,3>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_625 {}; public: ::cpp2::regex::regular_expression<char,0,2,0,::cpp2::regex::group_name_list<"n",1,::cpp2::regex::group_name_list_end>,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"n",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'f','f','F'>,::cpp2::regex::char_matcher_logic<char,'o','o','O'>,::cpp2::regex::char_matcher_logic<char,'o','o','O'>>,::cpp2::regex::group_matcher_end_logic<char,1>>,::cpp2::regex::char_matcher_logic<char,' ',' ',' '>,::cpp2::regex::group_ref_matcher_logic<char,1,"\\k<n>">>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_626 {}; public: ::cpp2::regex::regular_expression<char,0,2,0,::cpp2::regex::group_name_list<"n",1,::cpp2::regex::group_name_list_end>,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"n",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'f','f','F'>,::cpp2::regex::char_matcher_logic<char,'o','o','O'>,::cpp2::regex::char_matcher_logic<char,'o','o','O'>>,::cpp2::regex::group_matcher_end_logic<char,1>>,::cpp2::regex::char_matcher_logic<char,' ',' ',' '>,::cpp2::regex::group_ref_matcher_logic<char,1,"\\k<n>">>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_627 {}; public: ::cpp2::regex::regular_expression<char,0,2,0,::cpp2::regex::group_name_list<"n",1,::cpp2::regex::group_name_list_end>,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"n",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'f','f','F'>,::cpp2::regex::char_matcher_logic<char,'o','o','O'>,::cpp2::regex::char_matcher_logic<char,'o','o','O'>>,::cpp2::regex::group_matcher_end_logic<char,1>>,::cpp2::regex::char_matcher_logic<char,' ',' ',' '>,::cpp2::regex::group_ref_matcher_logic<char,1,"\\k'n'">>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_628 {}; public: ::cpp2::regex::regular_expression<char,0,2,0,::cpp2::regex::group_name_list<"n",1,::cpp2::regex::group_name_list_end>,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"n",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'f','f','F'>,::cpp2::regex::char_matcher_logic<char,'o','o','O'>,::cpp2::regex::char_matcher_logic<char,'o','o','O'>>,::cpp2::regex::group_matcher_end_logic<char,1>>,::cpp2::regex::char_matcher_logic<char,' ',' ',' '>,::cpp2::regex::group_ref_matcher_logic<char,1,"\\k'n'">>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_629 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,0,1,true,false,'?'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_63 {}; public: ::cpp2::regex::regular_expression<char,0,2,0,::cpp2::regex::group_name_list<"a1",1,::cpp2::regex::group_name_list_end>,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"a1",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'f','f','F'>,::cpp2::regex::char_matcher_logic<char,'o','o','O'>,::cpp2::regex::char_matcher_logic<char,'o','o','O'>>,::cpp2::regex::group_matcher_end_logic<char,1>>,::cpp2::regex::char_matcher_logic<char,' ',' ',' '>,::cpp2::regex::group_ref_matcher_logic<char,1,"\\k'a1'">>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_630 {}; public: ::cpp2::regex::regular_expression<char,0,2,0,::cpp2::regex::group_name_list<"a1",1,::cpp2::regex::group_name_list_end>,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"a1",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'f','f','F'>,::cpp2::regex::char_matcher_logic<char,'o','o','O'>,::cpp2::regex::char_matcher_logic<char,'o','o','O'>>,::cpp2::regex::group_matcher_end_logic<char,1>>,::cpp2::regex::char_matcher_logic<char,' ',' ',' '>,::cpp2::regex::group_ref_matcher_logic<char,1,"\\k<a1>">>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_631 {}; public: ::cpp2::regex::regular_expression<char,0,2,0,::cpp2::regex::group_name_list<"_",1,::cpp2::regex::group_name_list_end>,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"_",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'f','f','F'>,::cpp2::regex::char_matcher_logic<char,'o','o','O'>,::cpp2::regex::char_matcher_logic<char,'o','o','O'>>,::cpp2::regex::group_matcher_end_logic<char,1>>,::cpp2::regex::char_matcher_logic<char,' ',' ',' '>,::cpp2::regex::group_ref_matcher_logic<char,1,"\\k'_'">>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_632 {}; public: ::cpp2::regex::regular_expression<char,0,2,0,::cpp2::regex::group_name_list<"_",1,::cpp2::regex::group_name_list_end>,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"_",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'f','f','F'>,::cpp2::regex::char_matcher_logic<char,'o','o','O'>,::cpp2::regex::char_matcher_logic<char,'o','o','O'>>,::cpp2::regex::group_matcher_end_logic<char,1>>,::cpp2::regex::char_matcher_logic<char,' ',' ',' '>,::cpp2::regex::group_ref_matcher_logic<char,1,"\\k<_>">>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_633 {}; public: ::cpp2::regex::regular_expression<char,0,2,0,::cpp2::regex::group_name_list<"_0_",1,::cpp2::regex::group_name_list_end>,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"_0_",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'f','f','F'>,::cpp2::regex::char_matcher_logic<char,'o','o','O'>,::cpp2::regex::char_matcher_logic<char,'o','o','O'>>,::cpp2::regex::group_matcher_end_logic<char,1>>,::cpp2::regex::char_matcher_logic<char,' ',' ',' '>,::cpp2::regex::group_ref_matcher_logic<char,1,"\\k'_0_'">>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_634 {}; public: ::cpp2::regex::regular_expression<char,0,2,0,::cpp2::regex::group_name_list<"_0_",1,::cpp2::regex::group_name_list_end>,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"_0_",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'f','f','F'>,::cpp2::regex::char_matcher_logic<char,'o','o','O'>,::cpp2::regex::char_matcher_logic<char,'o','o','O'>>,::cpp2::regex::group_matcher_end_logic<char,1>>,::cpp2::regex::char_matcher_logic<char,' ',' ',' '>,::cpp2::regex::group_ref_matcher_logic<char,1,"\\k<_0_>">>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_635 {}; public: ::cpp2::regex::regular_expression<char,0,4,0,::cpp2::regex::group_name_list<"as",1,::cpp2::regex::group_name_list_end>,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"as",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'s','s','S'>>,::cpp2::regex::group_matcher_end_logic<char,1>>,::cpp2::regex::char_matcher_logic<char,' ',' ',' '>,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,2,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::named_class_word<char>,1,-1,true,false,'+'>>,::cpp2::regex::group_matcher_end_logic<char,2>>,::cpp2::regex::char_matcher_logic<char,' ',' ',' '>,::cpp2::regex::group_ref_matcher_logic<char,1,"\\k<as>">,::cpp2::regex::char_matcher_logic<char,' ',' ',' '>,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,3,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::named_class_word<char>,1,-1,true,false,'+'>>,::cpp2::regex::group_matcher_end_logic<char,3>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_636 {}; public: ::cpp2::regex::regular_expression<char,0,4,0,::cpp2::regex::group_name_list<"as",1,::cpp2::regex::group_name_list_end>,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"as",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'s','s','S'>>,::cpp2::regex::group_matcher_end_logic<char,1>>,::cpp2::regex::char_matcher_logic<char,' ',' ',' '>,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,2,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::named_class_word<char>,1,-1,true,false,'+'>>,::cpp2::regex::group_matcher_end_logic<char,2>>,::cpp2::regex::char_matcher_logic<char,' ',' ',' '>,::cpp2::regex::group_ref_matcher_logic<char,1,"\\k{as}">,::cpp2::regex::char_matcher_logic<char,' ',' ',' '>,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,3,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::named_class_word<char>,1,-1,true,false,'+'>>,::cpp2::regex::group_matcher_end_logic<char,3>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_637 {}; public: ::cpp2::regex::regular_expression<char,0,4,0,::cpp2::regex::group_name_list<"as",1,::cpp2::regex::group_name_list_end>,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"as",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'s','s','S'>>,::cpp2::regex::group_matcher_end_logic<char,1>>,::cpp2::regex::char_matcher_logic<char,' ',' ',' '>,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,2,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::named_class_word<char>,1,-1,true,false,'+'>>,::cpp2::regex::group_matcher_end_logic<char,2>>,::cpp2::regex::char_matcher_logic<char,' ',' ',' '>,::cpp2::regex::group_ref_matcher_logic<char,1,"\\k'as'">,::cpp2::regex::char_matcher_logic<char,' ',' ',' '>,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,3,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::named_class_word<char>,1,-1,true,false,'+'>>,::cpp2::regex::group_matcher_end_logic<char,3>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_638 {}; public: ::cpp2::regex::regular_expression<char,0,4,0,::cpp2::regex::group_name_list<"as",1,::cpp2::regex::group_name_list_end>,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"as",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'s','s','S'>>,::cpp2::regex::group_matcher_end_logic<char,1>>,::cpp2::regex::char_matcher_logic<char,' ',' ',' '>,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,2,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::named_class_word<char>,1,-1,true,false,'+'>>,::cpp2::regex::group_matcher_end_logic<char,2>>,::cpp2::regex::char_matcher_logic<char,' ',' ',' '>,::cpp2::regex::group_ref_matcher_logic<char,1,"\\k{ as }">,::cpp2::regex::char_matcher_logic<char,' ',' ',' '>,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,3,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::named_class_word<char>,1,-1,true,false,'+'>>,::cpp2::regex::group_matcher_end_logic<char,3>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_639 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,0,1,true,false>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_64 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::line_start_matcher_logic<char,true>,::cpp2::regex::range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,3,3,true,false>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_640 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::perl_code_syntax,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::line_start_matcher_logic<char,true>,::cpp2::regex::range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,3,3,true,false>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_641 {}; public: ::cpp2::regex::regular_expression<char,0,2,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::branch_reset_matcher_logic<char>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>>,::cpp2::regex::group_matcher_end_logic<char,1>>>,::cpp2::regex::special_group_end_logic<char>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_642 {}; public: ::cpp2::regex::regular_expression<char,0,4,1,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::branch_reset_matcher_logic<char>,::cpp2::regex::alternative_matcher_logic<char,0,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::any_matcher_logic<char>>,::cpp2::regex::group_matcher_end_logic<char,1>>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'d','d','D'>,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::any_matcher_logic<char>,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,2,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'o','o','O'>>,::cpp2::regex::group_matcher_end_logic<char,2>>,::cpp2::regex::any_matcher_logic<char>>,::cpp2::regex::group_matcher_end_logic<char,1>>,::cpp2::regex::char_matcher_logic<char,'d','d','D'>>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'i','i','I'>,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::any_matcher_logic<char>>,::cpp2::regex::group_matcher_end_logic<char,1>>,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,2,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::any_matcher_logic<char>>,::cpp2::regex::group_matcher_end_logic<char,2>>,::cpp2::regex::char_matcher_logic<char,'j','j','J'>>>,::cpp2::regex::special_group_end_logic<char>>,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,3,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::any_matcher_logic<char>>,::cpp2::regex::group_matcher_end_logic<char,3>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_643 {}; public: ::cpp2::regex::regular_expression<char,0,4,1,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::branch_reset_matcher_logic<char>,::cpp2::regex::alternative_matcher_logic<char,0,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::any_matcher_logic<char>>,::cpp2::regex::group_matcher_end_logic<char,1>>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'d','d','D'>,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::any_matcher_logic<char>,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,2,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'o','o','O'>>,::cpp2::regex::group_matcher_end_logic<char,2>>,::cpp2::regex::any_matcher_logic<char>>,::cpp2::regex::group_matcher_end_logic<char,1>>,::cpp2::regex::char_matcher_logic<char,'d','d','D'>>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'i','i','I'>,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::any_matcher_logic<char>>,::cpp2::regex::group_matcher_end_logic<char,1>>,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,2,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::any_matcher_logic<char>>,::cpp2::regex::group_matcher_end_logic<char,2>>,::cpp2::regex::char_matcher_logic<char,'j','j','J'>>>,::cpp2::regex::special_group_end_logic<char>>,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,3,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::any_matcher_logic<char>>,::cpp2::regex::group_matcher_end_logic<char,3>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_644 {}; public: ::cpp2::regex::regular_expression<char,0,4,1,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::branch_reset_matcher_logic<char>,::cpp2::regex::alternative_matcher_logic<char,0,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::any_matcher_logic<char>>,::cpp2::regex::group_matcher_end_logic<char,1>>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'d','d','D'>,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::any_matcher_logic<char>,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,2,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'o','o','O'>>,::cpp2::regex::group_matcher_end_logic<char,2>>,::cpp2::regex::any_matcher_logic<char>>,::cpp2::regex::group_matcher_end_logic<char,1>>,::cpp2::regex::char_matcher_logic<char,'d','d','D'>>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'i','i','I'>,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::any_matcher_logic<char>>,::cpp2::regex::group_matcher_end_logic<char,1>>,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,2,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::any_matcher_logic<char>>,::cpp2::regex::group_matcher_end_logic<char,2>>,::cpp2::regex::char_matcher_logic<char,'j','j','J'>>>,::cpp2::regex::special_group_end_logic<char>>,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,3,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::any_matcher_logic<char>>,::cpp2::regex::group_matcher_end_logic<char,3>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_645 {}; public: ::cpp2::regex::regular_expression<char,0,2,3,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::branch_reset_matcher_logic<char>,::cpp2::regex::alternative_matcher_logic<char,2,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::branch_reset_matcher_logic<char>,::cpp2::regex::alternative_matcher_logic<char,0,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>>,::cpp2::regex::group_matcher_end_logic<char,1>>>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>>,::cpp2::regex::group_matcher_end_logic<char,1>>>>,::cpp2::regex::special_group_end_logic<char>>>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::branch_reset_matcher_logic<char>,::cpp2::regex::alternative_matcher_logic<char,1,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,1>>>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'d','d','D'>>,::cpp2::regex::group_matcher_end_logic<char,1>>>>,::cpp2::regex::special_group_end_logic<char>>>>,::cpp2::regex::special_group_end_logic<char>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_646 {}; public: ::cpp2::regex::regular_expression<char,0,2,3,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::branch_reset_matcher_logic<char>,::cpp2::regex::alternative_matcher_logic<char,2,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::branch_reset_matcher_logic<char>,::cpp2::regex::alternative_matcher_logic<char,0,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>>,::cpp2::regex::group_matcher_end_logic<char,1>>>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>>,::cpp2::regex::group_matcher_end_logic<char,1>>>>,::cpp2::regex::special_group_end_logic<char>>>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::branch_reset_matcher_logic<char>,::cpp2::regex::alternative_matcher_logic<char,1,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,1>>>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'d','d','D'>>,::cpp2::regex::group_matcher_end_logic<char,1>>>>,::cpp2::regex::special_group_end_logic<char>>>>,::cpp2::regex::special_group_end_logic<char>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_647 {}; public: ::cpp2::regex::regular_expression<char,0,2,3,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::branch_reset_matcher_logic<char>,::cpp2::regex::alternative_matcher_logic<char,2,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::branch_reset_matcher_logic<char>,::cpp2::regex::alternative_matcher_logic<char,0,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>>,::cpp2::regex::group_matcher_end_logic<char,1>>>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>>,::cpp2::regex::group_matcher_end_logic<char,1>>>>,::cpp2::regex::special_group_end_logic<char>>>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::branch_reset_matcher_logic<char>,::cpp2::regex::alternative_matcher_logic<char,1,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,1>>>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'d','d','D'>>,::cpp2::regex::group_matcher_end_logic<char,1>>>>,::cpp2::regex::special_group_end_logic<char>>>>,::cpp2::regex::special_group_end_logic<char>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_648 {}; public: ::cpp2::regex::regular_expression<char,0,2,3,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::branch_reset_matcher_logic<char>,::cpp2::regex::alternative_matcher_logic<char,2,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::branch_reset_matcher_logic<char>,::cpp2::regex::alternative_matcher_logic<char,0,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>>,::cpp2::regex::group_matcher_end_logic<char,1>>>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>>,::cpp2::regex::group_matcher_end_logic<char,1>>>>,::cpp2::regex::special_group_end_logic<char>>>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::branch_reset_matcher_logic<char>,::cpp2::regex::alternative_matcher_logic<char,1,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,1>>>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'d','d','D'>>,::cpp2::regex::group_matcher_end_logic<char,1>>>>,::cpp2::regex::special_group_end_logic<char>>>>,::cpp2::regex::special_group_end_logic<char>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_649 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::line_start_matcher_logic<char,true>,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>,::cpp2::regex::line_end_matcher_logic<char,true,true>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_65 {}; public: ::cpp2::regex::regular_expression<char,0,5,1,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::any_matcher_logic<char>>,::cpp2::regex::group_matcher_end_logic<char,1>>,::cpp2::regex::matcher_list<char,::cpp2::regex::branch_reset_matcher_logic<char>,::cpp2::regex::alternative_matcher_logic<char,0,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,2,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::any_matcher_logic<char>>,::cpp2::regex::group_matcher_end_logic<char,2>>,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,3,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::any_matcher_logic<char>>,::cpp2::regex::group_matcher_end_logic<char,3>>,::cpp2::regex::char_matcher_logic<char,'x','x','X'>>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,2,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::any_matcher_logic<char>>,::cpp2::regex::group_matcher_end_logic<char,2>>,::cpp2::regex::char_matcher_logic<char,'d','d','D'>>>,::cpp2::regex::special_group_end_logic<char>>,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,4,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::any_matcher_logic<char>>,::cpp2::regex::group_matcher_end_logic<char,4>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_650 {}; public: ::cpp2::regex::regular_expression<char,0,5,1,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::named_class_no_new_line<char>>,::cpp2::regex::group_matcher_end_logic<char,1>>,::cpp2::regex::matcher_list<char,::cpp2::regex::branch_reset_matcher_logic<char>,::cpp2::regex::alternative_matcher_logic<char,0,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,2,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::named_class_no_new_line<char>>,::cpp2::regex::group_matcher_end_logic<char,2>>,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,3,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::named_class_no_new_line<char>>,::cpp2::regex::group_matcher_end_logic<char,3>>,::cpp2::regex::char_matcher_logic<char,'x','x','X'>>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,2,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::named_class_no_new_line<char>>,::cpp2::regex::group_matcher_end_logic<char,2>>,::cpp2::regex::char_matcher_logic<char,'d','d','D'>>>,::cpp2::regex::special_group_end_logic<char>>,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,4,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::named_class_no_new_line<char>>,::cpp2::regex::group_matcher_end_logic<char,4>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_651 {}; public: ::cpp2::regex::regular_expression<char,0,2,0,::cpp2::regex::group_name_list<"foo",1,::cpp2::regex::group_name_list_end>,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::branch_reset_matcher_logic<char>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"foo",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'x','x','X'>>,::cpp2::regex::group_matcher_end_logic<char,1>>>,::cpp2::regex::special_group_end_logic<char>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_652 {}; public: ::cpp2::regex::regular_expression<char,0,2,1,::cpp2::regex::group_name_list<"foo",1,::cpp2::regex::group_name_list<"bar",1,::cpp2::regex::group_name_list_end>>,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::branch_reset_matcher_logic<char>,::cpp2::regex::alternative_matcher_logic<char,0,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"foo",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'x','x','X'>>,::cpp2::regex::group_matcher_end_logic<char,1>>>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"bar",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'y','y','Y'>>,::cpp2::regex::group_matcher_end_logic<char,1>>>>,::cpp2::regex::special_group_end_logic<char>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_653 {}; public: ::cpp2::regex::regular_expression<char,0,2,1,::cpp2::regex::group_name_list<"foo",1,::cpp2::regex::group_name_list<"bar",1,::cpp2::regex::group_name_list_end>>,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::branch_reset_matcher_logic<char>,::cpp2::regex::alternative_matcher_logic<char,0,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"bar",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'y','y','Y'>>,::cpp2::regex::group_matcher_end_logic<char,1>>>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"foo",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'x','x','X'>>,::cpp2::regex::group_matcher_end_logic<char,1>>>>,::cpp2::regex::special_group_end_logic<char>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_654 {}; public: ::cpp2::regex::regular_expression<char,0,3,0,::cpp2::regex::group_name_list<"foo",2,::cpp2::regex::group_name_list<"bar",1,::cpp2::regex::group_name_list_end>>,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"bar",true>,::cpp2::regex::matcher_list<char>,::cpp2::regex::group_matcher_end_logic<char,1>>,::cpp2::regex::matcher_list<char,::cpp2::regex::branch_reset_matcher_logic<char>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,2,::cpp2::regex::match_modifiers_no_change,"foo",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'x','x','X'>>,::cpp2::regex::group_matcher_end_logic<char,2>>>,::cpp2::regex::special_group_end_logic<char>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_655 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'f','f','F'>,::cpp2::regex::char_matcher_logic<char,'o','o','O'>,::cpp2::regex::char_matcher_logic<char,'o','o','O'>,::cpp2::regex::global_group_reset<char>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'r','r','R'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_656 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'f','f','F'>,::cpp2::regex::char_matcher_logic<char,'o','o','O'>,::cpp2::regex::char_matcher_logic<char,'o','o','O'>,::cpp2::regex::special_syntax_wrapper<char,"\\t",::cpp2::regex::char_matcher_logic<char,'\t','\t','\t'>>,::cpp2::regex::special_syntax_wrapper<char,"\\n",::cpp2::regex::char_matcher_logic<char,'\n','\n','\n'>>,::cpp2::regex::special_syntax_wrapper<char,"\\r",::cpp2::regex::char_matcher_logic<char,'\r','\r','\r'>>,::cpp2::regex::special_syntax_wrapper<char,"\\f",::cpp2::regex::char_matcher_logic<char,'\f','\f','\f'>>,::cpp2::regex::special_syntax_wrapper<char,"\\a",::cpp2::regex::char_matcher_logic<char,'\a','\a','\a'>>,::cpp2::regex::special_syntax_wrapper<char,"\\e",::cpp2::regex::char_matcher_logic<char,'\e','\e','\e'>>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'r','r','R'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_657 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::no_group_captures,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,-1,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'f','f','F'>,::cpp2::regex::char_matcher_logic<char,'o','o','O'>,::cpp2::regex::char_matcher_logic<char,'o','o','O'>>,::cpp2::regex::group_matcher_end_logic<char,-1>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_658 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::no_group_captures,2,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::modifier_matcher_logic<char,::cpp2::regex::match_modifiers_state_change<true,false,0,8,"-n">>,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'f','f','F'>,::cpp2::regex::char_matcher_logic<char,'o','o','O'>,::cpp2::regex::char_matcher_logic<char,'o','o','O'>>,::cpp2::regex::group_matcher_end_logic<char,1>>,::cpp2::regex::modifier_matcher_logic<char,::cpp2::regex::match_modifiers_state_change<true,false,8,0,"n">>,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,-1,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'r','r','R'>>,::cpp2::regex::group_matcher_end_logic<char,-1>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_659 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::line_start_matcher_logic<char,true>,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>,::cpp2::regex::line_end_matcher_logic<char,true,true>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_66 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::no_group_captures,2,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,-1,::cpp2::regex::match_modifiers_state_change<true,false,0,8,"-n">,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'f','f','F'>,::cpp2::regex::char_matcher_logic<char,'o','o','O'>,::cpp2::regex::char_matcher_logic<char,'o','o','O'>>,::cpp2::regex::group_matcher_end_logic<char,1>>,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,-1,::cpp2::regex::match_modifiers_state_change<true,false,8,0,"n">,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,-1,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'r','r','R'>>,::cpp2::regex::group_matcher_end_logic<char,-1>>>,::cpp2::regex::group_matcher_end_logic<char,-1>>>,::cpp2::regex::group_matcher_end_logic<char,-1>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_660 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::perl_code_syntax,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'f','f','F'>,::cpp2::regex::char_matcher_logic<char,'o','o','O'>,::cpp2::regex::char_matcher_logic<char,'o','o','O'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_661 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::special_syntax_wrapper<char,"\x41",::cpp2::regex::char_matcher_logic<char,'A','a','A'>>,::cpp2::regex::special_syntax_wrapper<char,"\x42",::cpp2::regex::char_matcher_logic<char,'B','b','B'>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_662 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::special_syntax_wrapper<char,"\101",::cpp2::regex::char_matcher_logic<char,'A','a','A'>>,::cpp2::regex::special_syntax_wrapper<char,"\o{102}",::cpp2::regex::char_matcher_logic<char,'B','b','B'>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_663 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::line_start_matcher_logic<char,true>,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_67 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::line_start_matcher_logic<char,true>,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>,::cpp2::regex::line_end_matcher_logic<char,true,true>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_68 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>,::cpp2::regex::line_end_matcher_logic<char,true,true>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_69 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_7 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>,::cpp2::regex::line_end_matcher_logic<char,true,true>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_70 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::line_start_matcher_logic<char,true>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_71 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::line_end_matcher_logic<char,true,true>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_72 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::any_matcher_logic<char>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_73 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::any_matcher_logic<char>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_74 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::named_class_no_new_line<char>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_75 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::any_matcher_logic<char>,0,-1,true,false,'*'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_76 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::named_class_no_new_line<char>,0,-1,true,false,'*'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_77 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::any_matcher_logic<char>,0,-1,true,false,'*'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_78 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::named_class_no_new_line<char>,0,-1,true,false,'*'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_79 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_8 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::class_matcher_logic<char,false,::cpp2::regex::single_class_entry<char,'b'>,::cpp2::regex::single_class_entry<char,'c'>>,::cpp2::regex::char_matcher_logic<char,'d','d','D'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_80 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::class_matcher_logic<char,false,::cpp2::regex::single_class_entry<char,'b'>,::cpp2::regex::single_class_entry<char,'c'>>,::cpp2::regex::char_matcher_logic<char,'d','d','D'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_81 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::class_matcher_logic<char,false,::cpp2::regex::single_class_entry<char,'b'>>,::cpp2::regex::char_matcher_logic<char,'d','d','D'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_82 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::class_matcher_logic<char,false,::cpp2::regex::single_class_entry<char,'a'>>,::cpp2::regex::class_matcher_logic<char,false,::cpp2::regex::single_class_entry<char,'b'>>,::cpp2::regex::class_matcher_logic<char,false,::cpp2::regex::single_class_entry<char,'d'>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_83 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::any_matcher_logic<char>,::cpp2::regex::class_matcher_logic<char,false,::cpp2::regex::single_class_entry<char,'b'>>,::cpp2::regex::any_matcher_logic<char>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_84 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::any_matcher_logic<char>,::cpp2::regex::class_matcher_logic<char,false,::cpp2::regex::single_class_entry<char,'b'>>,::cpp2::regex::any_matcher_logic<char>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_85 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::class_matcher_logic<char,false,::cpp2::regex::range_class_entry<char,'b','d'>>,::cpp2::regex::char_matcher_logic<char,'e','e','E'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_86 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::class_matcher_logic<char,false,::cpp2::regex::range_class_entry<char,'b','d'>>,::cpp2::regex::char_matcher_logic<char,'e','e','E'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_87 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::class_matcher_logic<char,false,::cpp2::regex::range_class_entry<char,'b','d'>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_88 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::class_matcher_logic<char,false,::cpp2::regex::single_class_entry<char,'-'>,::cpp2::regex::single_class_entry<char,'b'>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_89 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_9 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::class_matcher_logic<char,false,::cpp2::regex::single_class_entry<char,'b'>,::cpp2::regex::single_class_entry<char,'-'>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_90 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,']',']',']'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_91 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::class_matcher_logic<char,false,::cpp2::regex::single_class_entry<char,']'>>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_92 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::class_matcher_logic<char,true,::cpp2::regex::single_class_entry<char,'b'>,::cpp2::regex::single_class_entry<char,'c'>>,::cpp2::regex::char_matcher_logic<char,'d','d','D'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_93 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::class_matcher_logic<char,true,::cpp2::regex::single_class_entry<char,'b'>,::cpp2::regex::single_class_entry<char,'c'>>,::cpp2::regex::char_matcher_logic<char,'d','d','D'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_94 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::class_matcher_logic<char,true,::cpp2::regex::single_class_entry<char,'-'>,::cpp2::regex::single_class_entry<char,'b'>>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_95 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::class_matcher_logic<char,true,::cpp2::regex::single_class_entry<char,'-'>,::cpp2::regex::single_class_entry<char,'b'>>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_96 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::class_matcher_logic<char,true,::cpp2::regex::single_class_entry<char,']'>,::cpp2::regex::single_class_entry<char,'b'>>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_97 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::class_matcher_logic<char,true,::cpp2::regex::single_class_entry<char,']'>,::cpp2::regex::single_class_entry<char,'b'>>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_98 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::word_boundary_matcher_logic<char,false>,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::word_boundary_matcher_logic<char,false>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_99 {}; 
  public: test_perl_tests_general() = default;
  public: test_perl_tests_general(test_perl_tests_general const&) = delete; /* No 'that' constructor, suppress copy */
  public: auto operator=(test_perl_tests_general const&) -> void = delete;


#line 2431 "pure2-regex.cpp2"
};
class test_perl_tests_lookahead {

  private: std::string var_regex_0 {"a(?!b)."}; 

  private: std::string var_regex_1 {"(?=)a"}; 

  private: std::string var_regex_2 {"a(?=d)."}; 

  private: std::string var_regex_3 {"a(?=c|d)."}; 

  private: std::string var_regex_4 {"^(?:b|a(?=(.)))*\1"}; 

  private: std::string var_regex_5 {"(?=(a+?))(\1ab)"}; 

  private: std::string var_regex_6 {"^(?=(a+?))\1ab"}; 

  private: std::string var_regex_7 {"(?=(a+?))(\1ab)"}; 

  private: std::string var_regex_8 {"^(?=(a+?))\1ab"}; 

  private: std::string var_regex_9 {"(.*)(?=c)"}; 

  private: std::string var_regex_10 {"(.*)(?=c)c"}; 

  private: std::string var_regex_11 {"(.*)(?=b|c)"}; 

  private: std::string var_regex_12 {"(.*)(?=b|c)c"}; 

  private: std::string var_regex_13 {"(.*)(?=c|b)"}; 

  private: std::string var_regex_14 {"(.*)(?=c|b)c"}; 

  private: std::string var_regex_15 {"(.*)(?=[bc])"}; 

  private: std::string var_regex_16 {"(.*)(?=[bc])c"}; 

  private: std::string var_regex_17 {"(.*?)(?=c)"}; 

  private: std::string var_regex_18 {"(.*?)(?=c)c"}; 

  private: std::string var_regex_19 {"(.*?)(?=b|c)"}; 

  private: std::string var_regex_20 {"(.*?)(?=b|c)c"}; 

  private: std::string var_regex_21 {"(.*?)(?=c|b)"}; 

  private: std::string var_regex_22 {"(.*?)(?=c|b)c"}; 

  private: std::string var_regex_23 {"(.*?)(?=[bc])"}; 

  private: std::string var_regex_24 {"(.*?)(?=[bc])c"}; 

  private: std::string var_regex_25 {"^(a*?)(?!(aa|aaaa)*\$)(?=a\z)"}; 

  private: std::string var_regex_26 {"a(?!b(?!c))(..)"}; 

  private: std::string var_regex_27 {"a(?!b(?=a))(..)"}; 

  private: std::string var_regex_28 {"X(\w+)(?=\s)|X(\w+)"}; 

  private: std::string var_regex_29 {"^a*(?=b)b"}; 

#line 2495 "pure2-regex.cpp2"
  private: std::string var_regex_30 {"(?!\A)x"}; 

#line 2498 "pure2-regex.cpp2"
  private: std::string var_regex_31 {"^(o)(?!.*\1)"}; 

  private: std::string var_regex_32 {".*a(?!(b|cd)*e).*f"}; 

  private: std::string var_regex_33 {"^(a*?)(?!(aa|aaaa)*\$)"}; 

  private: std::string var_regex_34 {"(?!)+?|(.{2,4})"}; 

  private: std::string var_regex_35 {"^(a*?)(?!(a{6}|a{5})*\$)"}; 

  private: std::string var_regex_36 {"a(?!b(?!c(?!d(?!e))))...(.)"}; 

  private: std::string var_regex_37 {"X(?!b+(?!(c+)*(?!(c+)*d))).*X"}; 

  private: std::string var_regex_38 {"((?s).)c(?!.)"}; 

  private: std::string var_regex_39 {"((?s).)c(?!.)"}; 

  private: std::string var_regex_40 {"((?s)b.)c(?!.)"}; 

  private: std::string var_regex_41 {"((?s)b.)c(?!.)"}; 

  private: std::string var_regex_42 {"((?s)b.)c(?!\\N)"}; 

#line 2523 "pure2-regex.cpp2"
  private: std::string var_regex_43 {"(b.)c(?!\\N)"}; 

  private: std::string var_regex_44 {"a*(?!)"}; 
  public: auto run() const& -> void;
  public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::lookahead_matcher_logic<char,false,"?!",::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>>>,::cpp2::regex::any_matcher_logic<char>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_0 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::lookahead_matcher_logic<char,true,"?=",::cpp2::regex::matcher_list<char>>,::cpp2::regex::char_matcher_logic<char,'a','a','A'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_1 {}; public: ::cpp2::regex::regular_expression<char,0,2,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::any_matcher_logic<char>,0,-1,true,false,'*'>>,::cpp2::regex::group_matcher_end_logic<char,1>>,::cpp2::regex::lookahead_matcher_logic<char,true,"?=",::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_10 {}; public: ::cpp2::regex::regular_expression<char,0,2,1,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::any_matcher_logic<char>,0,-1,true,false,'*'>>,::cpp2::regex::group_matcher_end_logic<char,1>>,::cpp2::regex::lookahead_matcher_logic<char,true,"?=",::cpp2::regex::alternative_matcher_logic<char,0,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_11 {}; public: ::cpp2::regex::regular_expression<char,0,2,1,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::any_matcher_logic<char>,0,-1,true,false,'*'>>,::cpp2::regex::group_matcher_end_logic<char,1>>,::cpp2::regex::lookahead_matcher_logic<char,true,"?=",::cpp2::regex::alternative_matcher_logic<char,0,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>>>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_12 {}; public: ::cpp2::regex::regular_expression<char,0,2,1,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::any_matcher_logic<char>,0,-1,true,false,'*'>>,::cpp2::regex::group_matcher_end_logic<char,1>>,::cpp2::regex::lookahead_matcher_logic<char,true,"?=",::cpp2::regex::alternative_matcher_logic<char,0,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>>>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_13 {}; public: ::cpp2::regex::regular_expression<char,0,2,1,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::any_matcher_logic<char>,0,-1,true,false,'*'>>,::cpp2::regex::group_matcher_end_logic<char,1>>,::cpp2::regex::lookahead_matcher_logic<char,true,"?=",::cpp2::regex::alternative_matcher_logic<char,0,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>>>>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_14 {}; public: ::cpp2::regex::regular_expression<char,0,2,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::any_matcher_logic<char>,0,-1,true,false,'*'>>,::cpp2::regex::group_matcher_end_logic<char,1>>,::cpp2::regex::lookahead_matcher_logic<char,true,"?=",::cpp2::regex::matcher_list<char,::cpp2::regex::class_matcher_logic<char,false,::cpp2::regex::single_class_entry<char,'b'>,::cpp2::regex::single_class_entry<char,'c'>>>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_15 {}; public: ::cpp2::regex::regular_expression<char,0,2,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::any_matcher_logic<char>,0,-1,true,false,'*'>>,::cpp2::regex::group_matcher_end_logic<char,1>>,::cpp2::regex::lookahead_matcher_logic<char,true,"?=",::cpp2::regex::matcher_list<char,::cpp2::regex::class_matcher_logic<char,false,::cpp2::regex::single_class_entry<char,'b'>,::cpp2::regex::single_class_entry<char,'c'>>>>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_16 {}; public: ::cpp2::regex::regular_expression<char,0,2,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::any_matcher_logic<char>,0,-1,false,false,'*'>>,::cpp2::regex::group_matcher_end_logic<char,1>>,::cpp2::regex::lookahead_matcher_logic<char,true,"?=",::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_17 {}; public: ::cpp2::regex::regular_expression<char,0,2,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::any_matcher_logic<char>,0,-1,false,false,'*'>>,::cpp2::regex::group_matcher_end_logic<char,1>>,::cpp2::regex::lookahead_matcher_logic<char,true,"?=",::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_18 {}; public: ::cpp2::regex::regular_expression<char,0,2,1,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::any_matcher_logic<char>,0,-1,false,false,'*'>>,::cpp2::regex::group_matcher_end_logic<char,1>>,::cpp2::regex::lookahead_matcher_logic<char,true,"?=",::cpp2::regex::alternative_matcher_logic<char,0,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_19 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::lookahead_matcher_logic<char,true,"?=",::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'d','d','D'>>>,::cpp2::regex::any_matcher_logic<char>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_2 {}; public: ::cpp2::regex::regular_expression<char,0,2,1,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::any_matcher_logic<char>,0,-1,false,false,'*'>>,::cpp2::regex::group_matcher_end_logic<char,1>>,::cpp2::regex::lookahead_matcher_logic<char,true,"?=",::cpp2::regex::alternative_matcher_logic<char,0,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>>>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_20 {}; public: ::cpp2::regex::regular_expression<char,0,2,1,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::any_matcher_logic<char>,0,-1,false,false,'*'>>,::cpp2::regex::group_matcher_end_logic<char,1>>,::cpp2::regex::lookahead_matcher_logic<char,true,"?=",::cpp2::regex::alternative_matcher_logic<char,0,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>>>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_21 {}; public: ::cpp2::regex::regular_expression<char,0,2,1,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::any_matcher_logic<char>,0,-1,false,false,'*'>>,::cpp2::regex::group_matcher_end_logic<char,1>>,::cpp2::regex::lookahead_matcher_logic<char,true,"?=",::cpp2::regex::alternative_matcher_logic<char,0,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>>>>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_22 {}; public: ::cpp2::regex::regular_expression<char,0,2,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::any_matcher_logic<char>,0,-1,false,false,'*'>>,::cpp2::regex::group_matcher_end_logic<char,1>>,::cpp2::regex::lookahead_matcher_logic<char,true,"?=",::cpp2::regex::matcher_list<char,::cpp2::regex::class_matcher_logic<char,false,::cpp2::regex::single_class_entry<char,'b'>,::cpp2::regex::single_class_entry<char,'c'>>>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_23 {}; public: ::cpp2::regex::regular_expression<char,0,2,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::any_matcher_logic<char>,0,-1,false,false,'*'>>,::cpp2::regex::group_matcher_end_logic<char,1>>,::cpp2::regex::lookahead_matcher_logic<char,true,"?=",::cpp2::regex::matcher_list<char,::cpp2::regex::class_matcher_logic<char,false,::cpp2::regex::single_class_entry<char,'b'>,::cpp2::regex::single_class_entry<char,'c'>>>>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_24 {}; public: ::cpp2::regex::regular_expression<char,0,3,1,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::line_start_matcher_logic<char,true>,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,0,-1,false,false,'*'>>,::cpp2::regex::group_matcher_end_logic<char,1>>,::cpp2::regex::lookahead_matcher_logic<char,false,"?!",::cpp2::regex::matcher_list<char,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,2,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::alternative_matcher_logic<char,0,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'a','a','A'>>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'a','a','A'>>>,::cpp2::regex::group_matcher_end_logic<char,2>>,0,-1,true,false,'*'>,::cpp2::regex::line_end_matcher_logic<char,true,true>>>,::cpp2::regex::lookahead_matcher_logic<char,true,"?=",::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::named_string_end<char>>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_25 {}; public: ::cpp2::regex::regular_expression<char,0,2,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::lookahead_matcher_logic<char,false,"?!",::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::lookahead_matcher_logic<char,false,"?!",::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>>>>,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::any_matcher_logic<char>,::cpp2::regex::any_matcher_logic<char>>,::cpp2::regex::group_matcher_end_logic<char,1>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_26 {}; public: ::cpp2::regex::regular_expression<char,0,2,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::lookahead_matcher_logic<char,false,"?!",::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::lookahead_matcher_logic<char,true,"?=",::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>>>>>,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::any_matcher_logic<char>,::cpp2::regex::any_matcher_logic<char>>,::cpp2::regex::group_matcher_end_logic<char,1>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_27 {}; public: ::cpp2::regex::regular_expression<char,0,3,1,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::alternative_matcher_logic<char,0,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'X','x','X'>,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::named_class_word<char>,1,-1,true,false,'+'>>,::cpp2::regex::group_matcher_end_logic<char,1>>,::cpp2::regex::lookahead_matcher_logic<char,true,"?=",::cpp2::regex::matcher_list<char,::cpp2::regex::named_class_space<char>>>>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'X','x','X'>,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,2,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::named_class_word<char>,1,-1,true,false,'+'>>,::cpp2::regex::group_matcher_end_logic<char,2>>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_28 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::line_start_matcher_logic<char,true>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,0,-1,true,false,'*'>,::cpp2::regex::lookahead_matcher_logic<char,true,"?=",::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>>>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_29 {}; public: ::cpp2::regex::regular_expression<char,0,1,1,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::lookahead_matcher_logic<char,true,"?=",::cpp2::regex::alternative_matcher_logic<char,0,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'d','d','D'>>>>,::cpp2::regex::any_matcher_logic<char>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_3 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::multiple_lines,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::lookahead_matcher_logic<char,false,"?!",::cpp2::regex::matcher_list<char,::cpp2::regex::named_string_start<char>>>,::cpp2::regex::char_matcher_logic<char,'x','x','X'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_30 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::case_insensitive,2,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::line_start_matcher_logic<char,true>,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'o','o','O'>>,::cpp2::regex::group_matcher_end_logic<char,1>>,::cpp2::regex::lookahead_matcher_logic<char,false,"?!",::cpp2::regex::matcher_list<char,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::any_matcher_logic<char>,0,-1,true,false,'*'>,::cpp2::regex::group_ref_matcher_logic<char,1,"\\1">>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_31 {}; public: ::cpp2::regex::regular_expression<char,0,2,1,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::any_matcher_logic<char>,0,-1,true,false,'*'>,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::lookahead_matcher_logic<char,false,"?!",::cpp2::regex::matcher_list<char,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::alternative_matcher_logic<char,0,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'c','c','C'>,::cpp2::regex::char_matcher_logic<char,'d','d','D'>>>,::cpp2::regex::group_matcher_end_logic<char,1>>,0,-1,true,false,'*'>,::cpp2::regex::char_matcher_logic<char,'e','e','E'>>>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::any_matcher_logic<char>,0,-1,true,false,'*'>,::cpp2::regex::char_matcher_logic<char,'f','f','F'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_32 {}; public: ::cpp2::regex::regular_expression<char,0,3,1,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::line_start_matcher_logic<char,true>,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,0,-1,false,false,'*'>>,::cpp2::regex::group_matcher_end_logic<char,1>>,::cpp2::regex::lookahead_matcher_logic<char,false,"?!",::cpp2::regex::matcher_list<char,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,2,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::alternative_matcher_logic<char,0,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'a','a','A'>>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'a','a','A'>>>,::cpp2::regex::group_matcher_end_logic<char,2>>,0,-1,true,false,'*'>,::cpp2::regex::line_end_matcher_logic<char,true,true>>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_33 {}; public: ::cpp2::regex::regular_expression<char,0,2,1,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::alternative_matcher_logic<char,0,::cpp2::regex::matcher_list<char,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::lookahead_matcher_logic<char,false,"?!",::cpp2::regex::matcher_list<char>>,1,-1,false,false,'+'>>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::range_matcher_logic<char,::cpp2::regex::any_matcher_logic<char>,2,4,true,false>>,::cpp2::regex::group_matcher_end_logic<char,1>>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_34 {}; public: ::cpp2::regex::regular_expression<char,0,3,1,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::line_start_matcher_logic<char,true>,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,0,-1,false,false,'*'>>,::cpp2::regex::group_matcher_end_logic<char,1>>,::cpp2::regex::lookahead_matcher_logic<char,false,"?!",::cpp2::regex::matcher_list<char,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,2,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::alternative_matcher_logic<char,0,::cpp2::regex::matcher_list<char,::cpp2::regex::range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,6,6,true,false>>,::cpp2::regex::matcher_list<char,::cpp2::regex::range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,5,5,true,false>>>,::cpp2::regex::group_matcher_end_logic<char,2>>,0,-1,true,false,'*'>,::cpp2::regex::line_end_matcher_logic<char,true,true>>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_35 {}; public: ::cpp2::regex::regular_expression<char,0,2,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::lookahead_matcher_logic<char,false,"?!",::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::lookahead_matcher_logic<char,false,"?!",::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'c','c','C'>,::cpp2::regex::lookahead_matcher_logic<char,false,"?!",::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'d','d','D'>,::cpp2::regex::lookahead_matcher_logic<char,false,"?!",::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'e','e','E'>>>>>>>>>,::cpp2::regex::any_matcher_logic<char>,::cpp2::regex::any_matcher_logic<char>,::cpp2::regex::any_matcher_logic<char>,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::any_matcher_logic<char>>,::cpp2::regex::group_matcher_end_logic<char,1>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_36 {}; public: ::cpp2::regex::regular_expression<char,0,3,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'X','x','X'>,::cpp2::regex::lookahead_matcher_logic<char,false,"?!",::cpp2::regex::matcher_list<char,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,1,-1,true,false,'+'>,::cpp2::regex::lookahead_matcher_logic<char,false,"?!",::cpp2::regex::matcher_list<char,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'c','c','C'>,1,-1,true,false,'+'>>,::cpp2::regex::group_matcher_end_logic<char,1>>,0,-1,true,false,'*'>,::cpp2::regex::lookahead_matcher_logic<char,false,"?!",::cpp2::regex::matcher_list<char,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,2,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'c','c','C'>,1,-1,true,false,'+'>>,::cpp2::regex::group_matcher_end_logic<char,2>>,0,-1,true,false,'*'>,::cpp2::regex::char_matcher_logic<char,'d','d','D'>>>>>>>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::any_matcher_logic<char>,0,-1,true,false,'*'>,::cpp2::regex::char_matcher_logic<char,'X','x','X'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_37 {}; public: ::cpp2::regex::regular_expression<char,0,2,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::modifier_matcher_logic<char,::cpp2::regex::match_modifiers_state_change<true,false,4,0,"s">>,::cpp2::regex::any_matcher_logic<char>>,::cpp2::regex::group_matcher_end_logic<char,1>>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>,::cpp2::regex::lookahead_matcher_logic<char,false,"?!",::cpp2::regex::matcher_list<char,::cpp2::regex::any_matcher_logic<char>>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_38 {}; public: ::cpp2::regex::regular_expression<char,0,2,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::modifier_matcher_logic<char,::cpp2::regex::match_modifiers_state_change<true,false,4,0,"s">>,::cpp2::regex::any_matcher_logic<char>>,::cpp2::regex::group_matcher_end_logic<char,1>>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>,::cpp2::regex::lookahead_matcher_logic<char,false,"?!",::cpp2::regex::matcher_list<char,::cpp2::regex::any_matcher_logic<char>>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_39 {}; public: ::cpp2::regex::regular_expression<char,0,2,1,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::line_start_matcher_logic<char,true>,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,-1,::cpp2::regex::match_modifiers_state_change<true,false,0,0,"">,"",true>,::cpp2::regex::alternative_matcher_logic<char,0,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::lookahead_matcher_logic<char,true,"?=",::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::any_matcher_logic<char>>,::cpp2::regex::group_matcher_end_logic<char,1>>>>>>,::cpp2::regex::group_matcher_end_logic<char,-1>>,0,-1,true,false,'*'>,::cpp2::regex::group_ref_matcher_logic<char,1,"\\1">>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_4 {}; public: ::cpp2::regex::regular_expression<char,0,2,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::modifier_matcher_logic<char,::cpp2::regex::match_modifiers_state_change<true,false,4,0,"s">>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::any_matcher_logic<char>>,::cpp2::regex::group_matcher_end_logic<char,1>>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>,::cpp2::regex::lookahead_matcher_logic<char,false,"?!",::cpp2::regex::matcher_list<char,::cpp2::regex::any_matcher_logic<char>>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_40 {}; public: ::cpp2::regex::regular_expression<char,0,2,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::modifier_matcher_logic<char,::cpp2::regex::match_modifiers_state_change<true,false,4,0,"s">>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::any_matcher_logic<char>>,::cpp2::regex::group_matcher_end_logic<char,1>>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>,::cpp2::regex::lookahead_matcher_logic<char,false,"?!",::cpp2::regex::matcher_list<char,::cpp2::regex::any_matcher_logic<char>>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_41 {}; public: ::cpp2::regex::regular_expression<char,0,2,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::modifier_matcher_logic<char,::cpp2::regex::match_modifiers_state_change<true,false,4,0,"s">>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::any_matcher_logic<char>>,::cpp2::regex::group_matcher_end_logic<char,1>>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>,::cpp2::regex::lookahead_matcher_logic<char,false,"?!",::cpp2::regex::matcher_list<char,::cpp2::regex::named_class_no_new_line<char>>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_42 {}; public: ::cpp2::regex::regular_expression<char,0 | ::cpp2::regex::expression_flags::single_line,2,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'b','b','B'>,::cpp2::regex::any_matcher_logic<char>>,::cpp2::regex::group_matcher_end_logic<char,1>>,::cpp2::regex::char_matcher_logic<char,'c','c','C'>,::cpp2::regex::lookahead_matcher_logic<char,false,"?!",::cpp2::regex::matcher_list<char,::cpp2::regex::named_class_no_new_line<char>>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_43 {}; public: ::cpp2::regex::regular_expression<char,0,1,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,0,-1,true,false,'*'>,::cpp2::regex::lookahead_matcher_logic<char,false,"?!",::cpp2::regex::matcher_list<char>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_44 {}; public: ::cpp2::regex::regular_expression<char,0,3,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::lookahead_matcher_logic<char,true,"?=",::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,1,-1,false,false,'+'>>,::cpp2::regex::group_matcher_end_logic<char,1>>>>,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,2,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::group_ref_matcher_logic<char,1,"\\1">,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>>,::cpp2::regex::group_matcher_end_logic<char,2>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_5 {}; public: ::cpp2::regex::regular_expression<char,0,2,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::line_start_matcher_logic<char,true>,::cpp2::regex::lookahead_matcher_logic<char,true,"?=",::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,1,-1,false,false,'+'>>,::cpp2::regex::group_matcher_end_logic<char,1>>>>,::cpp2::regex::group_ref_matcher_logic<char,1,"\\1">,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_6 {}; public: ::cpp2::regex::regular_expression<char,0,3,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::lookahead_matcher_logic<char,true,"?=",::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,1,-1,false,false,'+'>>,::cpp2::regex::group_matcher_end_logic<char,1>>>>,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,2,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::group_ref_matcher_logic<char,1,"\\1">,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>>,::cpp2::regex::group_matcher_end_logic<char,2>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_7 {}; public: ::cpp2::regex::regular_expression<char,0,2,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::line_start_matcher_logic<char,true>,::cpp2::regex::lookahead_matcher_logic<char,true,"?=",::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,1,-1,false,false,'+'>>,::cpp2::regex::group_matcher_end_logic<char,1>>>>,::cpp2::regex::group_ref_matcher_logic<char,1,"\\1">,::cpp2::regex::char_matcher_logic<char,'a','a','A'>,::cpp2::regex::char_matcher_logic<char,'b','b','B'>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_8 {}; public: ::cpp2::regex::regular_expression<char,0,2,0,::cpp2::regex::group_name_list_end,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,0,::cpp2::regex::match_modifiers_no_change,"",false>,::cpp2::regex::matcher_list<char,::cpp2::regex::matcher_list<char,::cpp2::regex::group_matcher_start_logic<char,1,::cpp2::regex::match_modifiers_no_change,"",true>,::cpp2::regex::matcher_list<char,::cpp2::regex::special_range_matcher_logic<char,::cpp2::regex::any_matcher_logic<char>,0,-1,true,false,'*'>>,::cpp2::regex::group_matcher_end_logic<char,1>>,::cpp2::regex::lookahead_matcher_logic<char,true,"?=",::cpp2::regex::matcher_list<char,::cpp2::regex::char_matcher_logic<char,'c','c','C'>>>>,::cpp2::regex::group_matcher_end_logic<char,0>>> regex_9 {}; 
  public: test_perl_tests_lookahead() = default;
  public: test_perl_tests_lookahead(test_perl_tests_lookahead const&) = delete; /* No 'that' constructor, suppress copy */
  public: auto operator=(test_perl_tests_lookahead const&) -> void = delete;


#line 2575 "pure2-regex.cpp2"
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
  auto extract_until {[](auto& iter, cpp2::in<char> to) mutable -> auto{
    auto start {iter}; 

    for( ; (to != *cpp2::assert_not_null(iter)); ++iter ) {}// TODO: Without bracket: error: postfix unary * (dereference) cannot be immediately followed by a (, identifier, or literal - add whitespace before * here if you meant binary * (multiplication)

    return std::string(std::move(start), iter); 
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
          if (*cpp2::assert_not_null(next) == '{') {
            ++next; // Skip {
            auto group {extract_until(next, '}')}; 
            ++next; // Skip }
            result += CPP2_UFCS(group)(r, group);
          }
          else {if (*cpp2::assert_not_null(next) == '[') {
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
          else {
            // Return max group
            result += CPP2_UFCS(group)(r, CPP2_UFCS(group_number)(r) - 1);
          }}
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

#line 112 "pure2-regex.cpp2"
template<typename M> auto test(M const& regex, cpp2::in<int> id, cpp2::in<std::string> regex_str, cpp2::in<std::string> str, cpp2::in<std::string> kind, cpp2::in<std::string> resultExpr, 
           cpp2::in<std::string> resultExpected) -> void{

  std::string warning {""}; 
  if (CPP2_UFCS(to_string)(regex) != regex_str) {
    warning = "Warning: Parsed regex does not match.";
  }

  std::string status {"OK"}; 

  auto r {CPP2_UFCS(search)(regex, str)}; 

  if ("y" == kind || "yM" == kind || "yS" == kind || "yB" == kind) {
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

#line 1763 "pure2-regex.cpp2"
  auto test_perl_tests_general::run() const& -> void{
    std::cout << "Running perl_tests_general:" << std::endl;
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
    test(regex_338, 338, "(?:(?i)a)b", "ab", "y", "$&", "ab");
    test(regex_339, 339, "((?i)a)b", "ab", "y", "$&:$1", "ab:a");
    test(regex_340, 340, "(?:(?i)a)b", "Ab", "y", "$&", "Ab");
    test(regex_341, 341, "((?i)a)b", "Ab", "y", "$&:$1", "Ab:A");
    test(regex_342, 342, "(?:(?i)a)b", "aB", "n", "-", "-");
    test(regex_343, 343, "((?i)a)b", "aB", "n", "-", "-");
    test(regex_344, 344, "(?i:a)b", "ab", "y", "$&", "ab");
    test(regex_345, 345, "((?i:a))b", "ab", "y", "$&:$1", "ab:a");
    test(regex_346, 346, "(?i:a)b", "Ab", "y", "$&", "Ab");
    test(regex_347, 347, "((?i:a))b", "Ab", "y", "$&:$1", "Ab:A");
    test(regex_348, 348, "(?i:a)b", "aB", "n", "-", "-");
    test(regex_349, 349, "((?i:a))b", "aB", "n", "-", "-");
    test(regex_350, 350, "(?:(?-i)a)b", "ab", "y", "$&", "ab");
    test(regex_351, 351, "((?-i)a)b", "ab", "y", "$&:$1", "ab:a");
    test(regex_352, 352, "(?:(?-i)a)b", "aB", "y", "$&", "aB");
    test(regex_353, 353, "((?-i)a)b", "aB", "y", "$&:$1", "aB:a");
    test(regex_354, 354, "(?:(?-i)a)b", "Ab", "n", "-", "-");
    test(regex_355, 355, "((?-i)a)b", "Ab", "n", "-", "-");
    test(regex_356, 356, "(?:(?-i)a)b", "aB", "y", "$&", "aB");
    test(regex_357, 357, "((?-i)a)b", "aB", "y", "$1", "a");
    test(regex_358, 358, "(?:(?-i)a)b", "AB", "n", "-", "-");
    test(regex_359, 359, "((?-i)a)b", "AB", "n", "-", "-");
    test(regex_360, 360, "(?-i:a)b", "ab", "y", "$&", "ab");
    test(regex_361, 361, "((?-i:a))b", "ab", "y", "$&:$1", "ab:a");
    test(regex_362, 362, "(?-i:a)b", "aB", "y", "$&", "aB");
    test(regex_363, 363, "((?-i:a))b", "aB", "y", "$&:$1", "aB:a");
    test(regex_364, 364, "(?-i:a)b", "Ab", "n", "-", "-");
    test(regex_365, 365, "((?-i:a))b", "Ab", "n", "-", "-");
    test(regex_366, 366, "(?-i:a)b", "aB", "y", "$&", "aB");
    test(regex_367, 367, "((?-i:a))b", "aB", "y", "$1", "a");
    test(regex_368, 368, "(?-i:a)b", "AB", "n", "-", "-");
    test(regex_369, 369, "((?-i:a))b", "AB", "n", "-", "-");
    test(regex_370, 370, "((?-i:a.))b", "a\nB", "n", "-", "-");
    test(regex_371, 371, "((?-i:a\\\\N))b", "a\nB", "n", "-", "-");
    test(regex_372, 372, "((?s-i:a.))b", "a\nB", "y", "$1", "a\n");
    test(regex_373, 373, "((?s-i:a\\\\N))b", "a\nB", "n", "-", "-");
    test(regex_374, 374, "((?s-i:a.))b", "B\nB", "n", "-", "-");
    test(regex_375, 375, "((?s-i:a\\\\N))b", "B\nB", "n", "-", "-");
    test(regex_376, 376, "^(?:a?b?)*\\$", "a--", "n", "-", "-");
    test(regex_377, 377, "((?s)^a(.))((?m)^b\\$)", "a\nb\nc\n", "y", "$1;$2;$3", "a\n;\n;b");
    test(regex_378, 378, "((?m)^b\\$)", "a\nb\nc\n", "y", "$1", "b");
    test(regex_379, 379, "(?m)^b", "a\nb\n", "y", "$&", "b");
    test(regex_380, 380, "(?m)^(b)", "a\nb\n", "y", "$1", "b");
    test(regex_381, 381, "((?m)^b)", "a\nb\n", "y", "$1", "b");
    test(regex_382, 382, "\\n((?m)^b)", "a\nb\n", "y", "$1", "b");
    test(regex_383, 383, "^b", "a\nb\nc\n", "n", "-", "-");
    test(regex_384, 384, "()^b", "a\nb\nc\n", "n", "-", "-");
    test(regex_385, 385, "((?m)^b)", "a\nb\nc\n", "y", "$1", "b");
    test(regex_386, 386, "\\Z", "a\nb\n", "y", "$-[0]", "3");
    test(regex_387, 387, "\\z", "a\nb\n", "y", "$-[0]", "4");
    test(regex_388, 388, "\\$", "a\nb\n", "y", "$-[0]", "3");
    test(regex_389, 389, "\\Z", "b\na\n", "y", "$-[0]", "3");
    test(regex_390, 390, "\\z", "b\na\n", "y", "$-[0]", "4");
    test(regex_391, 391, "\\$", "b\na\n", "y", "$-[0]", "3");
    test(regex_392, 392, "\\Z", "b\na", "y", "$-[0]", "3");
    test(regex_393, 393, "\\z", "b\na", "y", "$-[0]", "3");
    test(regex_394, 394, "\\$", "b\na", "y", "$-[0]", "3");
    test(regex_395, 395, "\\Z", "a\nb\n", "y", "$-[0]", "3");
    test(regex_396, 396, "\\z", "a\nb\n", "y", "$-[0]", "4");
    test(regex_397, 397, "\\$", "a\nb\n", "y", "$-[0]", "1");
    test(regex_398, 398, "\\Z", "b\na\n", "y", "$-[0]", "3");
    test(regex_399, 399, "\\z", "b\na\n", "y", "$-[0]", "4");
    test(regex_400, 400, "\\$", "b\na\n", "y", "$-[0]", "1");
    test(regex_401, 401, "\\Z", "b\na", "y", "$-[0]", "3");
    test(regex_402, 402, "\\z", "b\na", "y", "$-[0]", "3");
    test(regex_403, 403, "\\$", "b\na", "y", "$-[0]", "1");
    test(regex_404, 404, "a\\Z", "a\nb\n", "n", "-", "-");
    test(regex_405, 405, "a\\z", "a\nb\n", "n", "-", "-");
    test(regex_406, 406, "a\\$", "a\nb\n", "n", "-", "-");
    test(regex_407, 407, "a\\Z", "b\na\n", "y", "$-[0]", "2");
    test(regex_408, 408, "a\\z", "b\na\n", "n", "-", "-");
    test(regex_409, 409, "a\\$", "b\na\n", "y", "$-[0]", "2");
    test(regex_410, 410, "a\\Z", "b\na", "y", "$-[0]", "2");
    test(regex_411, 411, "a\\z", "b\na", "y", "$-[0]", "2");
    test(regex_412, 412, "a\\$", "b\na", "y", "$-[0]", "2");
    test(regex_413, 413, "a\\Z", "a\nb\n", "n", "-", "-");
    test(regex_414, 414, "a\\z", "a\nb\n", "n", "-", "-");
    test(regex_415, 415, "a\\$", "a\nb\n", "y", "$-[0]", "0");
    test(regex_416, 416, "a\\Z", "b\na\n", "y", "$-[0]", "2");
    test(regex_417, 417, "a\\z", "b\na\n", "n", "-", "-");
    test(regex_418, 418, "a\\$", "b\na\n", "y", "$-[0]", "2");
    test(regex_419, 419, "a\\Z", "b\na", "y", "$-[0]", "2");
    test(regex_420, 420, "a\\z", "b\na", "y", "$-[0]", "2");
    test(regex_421, 421, "a\\$", "b\na", "y", "$-[0]", "2");
    test(regex_422, 422, "aa\\Z", "aa\nb\n", "n", "-", "-");
    test(regex_423, 423, "aa\\z", "aa\nb\n", "n", "-", "-");
    test(regex_424, 424, "aa\\$", "aa\nb\n", "n", "-", "-");
    test(regex_425, 425, "aa\\Z", "b\naa\n", "y", "$-[0]", "2");
    test(regex_426, 426, "aa\\z", "b\naa\n", "n", "-", "-");
    test(regex_427, 427, "aa\\$", "b\naa\n", "y", "$-[0]", "2");
    test(regex_428, 428, "aa\\Z", "b\naa", "y", "$-[0]", "2");
    test(regex_429, 429, "aa\\z", "b\naa", "y", "$-[0]", "2");
    test(regex_430, 430, "aa\\$", "b\naa", "y", "$-[0]", "2");
    test(regex_431, 431, "aa\\Z", "aa\nb\n", "n", "-", "-");
    test(regex_432, 432, "aa\\z", "aa\nb\n", "n", "-", "-");
    test(regex_433, 433, "aa\\$", "aa\nb\n", "y", "$-[0]", "0");
    test(regex_434, 434, "aa\\Z", "b\naa\n", "y", "$-[0]", "2");
    test(regex_435, 435, "aa\\z", "b\naa\n", "n", "-", "-");
    test(regex_436, 436, "aa\\$", "b\naa\n", "y", "$-[0]", "2");
    test(regex_437, 437, "aa\\Z", "b\naa", "y", "$-[0]", "2");
    test(regex_438, 438, "aa\\z", "b\naa", "y", "$-[0]", "2");
    test(regex_439, 439, "aa\\$", "b\naa", "y", "$-[0]", "2");
    test(regex_440, 440, "aa\\Z", "ac\nb\n", "n", "-", "-");
    test(regex_441, 441, "aa\\z", "ac\nb\n", "n", "-", "-");
    test(regex_442, 442, "aa\\$", "ac\nb\n", "n", "-", "-");
    test(regex_443, 443, "aa\\Z", "b\nac\n", "n", "-", "-");
    test(regex_444, 444, "aa\\z", "b\nac\n", "n", "-", "-");
    test(regex_445, 445, "aa\\$", "b\nac\n", "n", "-", "-");
    test(regex_446, 446, "aa\\Z", "b\nac", "n", "-", "-");
    test(regex_447, 447, "aa\\z", "b\nac", "n", "-", "-");
    test(regex_448, 448, "aa\\$", "b\nac", "n", "-", "-");
    test(regex_449, 449, "aa\\Z", "ac\nb\n", "n", "-", "-");
    test(regex_450, 450, "aa\\z", "ac\nb\n", "n", "-", "-");
    test(regex_451, 451, "aa\\$", "ac\nb\n", "n", "-", "-");
    test(regex_452, 452, "aa\\Z", "b\nac\n", "n", "-", "-");
    test(regex_453, 453, "aa\\z", "b\nac\n", "n", "-", "-");
    test(regex_454, 454, "aa\\$", "b\nac\n", "n", "-", "-");
    test(regex_455, 455, "aa\\Z", "b\nac", "n", "-", "-");
    test(regex_456, 456, "aa\\z", "b\nac", "n", "-", "-");
    test(regex_457, 457, "aa\\$", "b\nac", "n", "-", "-");
    test(regex_458, 458, "aa\\Z", "ca\nb\n", "n", "-", "-");
    test(regex_459, 459, "aa\\z", "ca\nb\n", "n", "-", "-");
    test(regex_460, 460, "aa\\$", "ca\nb\n", "n", "-", "-");
    test(regex_461, 461, "aa\\Z", "b\nca\n", "n", "-", "-");
    test(regex_462, 462, "aa\\z", "b\nca\n", "n", "-", "-");
    test(regex_463, 463, "aa\\$", "b\nca\n", "n", "-", "-");
    test(regex_464, 464, "aa\\Z", "b\nca", "n", "-", "-");
    test(regex_465, 465, "aa\\z", "b\nca", "n", "-", "-");
    test(regex_466, 466, "aa\\$", "b\nca", "n", "-", "-");
    test(regex_467, 467, "aa\\Z", "ca\nb\n", "n", "-", "-");
    test(regex_468, 468, "aa\\z", "ca\nb\n", "n", "-", "-");
    test(regex_469, 469, "aa\\$", "ca\nb\n", "n", "-", "-");
    test(regex_470, 470, "aa\\Z", "b\nca\n", "n", "-", "-");
    test(regex_471, 471, "aa\\z", "b\nca\n", "n", "-", "-");
    test(regex_472, 472, "aa\\$", "b\nca\n", "n", "-", "-");
    test(regex_473, 473, "aa\\Z", "b\nca", "n", "-", "-");
    test(regex_474, 474, "aa\\z", "b\nca", "n", "-", "-");
    test(regex_475, 475, "aa\\$", "b\nca", "n", "-", "-");
    test(regex_476, 476, "ab\\Z", "ab\nb\n", "n", "-", "-");
    test(regex_477, 477, "ab\\z", "ab\nb\n", "n", "-", "-");
    test(regex_478, 478, "ab\\$", "ab\nb\n", "n", "-", "-");
    test(regex_479, 479, "ab\\Z", "b\nab\n", "y", "$-[0]", "2");
    test(regex_480, 480, "ab\\z", "b\nab\n", "n", "-", "-");
    test(regex_481, 481, "ab\\$", "b\nab\n", "y", "$-[0]", "2");
    test(regex_482, 482, "ab\\Z", "b\nab", "y", "$-[0]", "2");
    test(regex_483, 483, "ab\\z", "b\nab", "y", "$-[0]", "2");
    test(regex_484, 484, "ab\\$", "b\nab", "y", "$-[0]", "2");
    test(regex_485, 485, "ab\\Z", "ab\nb\n", "n", "-", "-");
    test(regex_486, 486, "ab\\z", "ab\nb\n", "n", "-", "-");
    test(regex_487, 487, "ab\\$", "ab\nb\n", "y", "$-[0]", "0");
    test(regex_488, 488, "ab\\Z", "b\nab\n", "y", "$-[0]", "2");
    test(regex_489, 489, "ab\\z", "b\nab\n", "n", "-", "-");
    test(regex_490, 490, "ab\\$", "b\nab\n", "y", "$-[0]", "2");
    test(regex_491, 491, "ab\\Z", "b\nab", "y", "$-[0]", "2");
    test(regex_492, 492, "ab\\z", "b\nab", "y", "$-[0]", "2");
    test(regex_493, 493, "ab\\$", "b\nab", "y", "$-[0]", "2");
    test(regex_494, 494, "ab\\Z", "ac\nb\n", "n", "-", "-");
    test(regex_495, 495, "ab\\z", "ac\nb\n", "n", "-", "-");
    test(regex_496, 496, "ab\\$", "ac\nb\n", "n", "-", "-");
    test(regex_497, 497, "ab\\Z", "b\nac\n", "n", "-", "-");
    test(regex_498, 498, "ab\\z", "b\nac\n", "n", "-", "-");
    test(regex_499, 499, "ab\\$", "b\nac\n", "n", "-", "-");
    test(regex_500, 500, "ab\\Z", "b\nac", "n", "-", "-");
    test(regex_501, 501, "ab\\z", "b\nac", "n", "-", "-");
    test(regex_502, 502, "ab\\$", "b\nac", "n", "-", "-");
    test(regex_503, 503, "ab\\Z", "ac\nb\n", "n", "-", "-");
    test(regex_504, 504, "ab\\z", "ac\nb\n", "n", "-", "-");
    test(regex_505, 505, "ab\\$", "ac\nb\n", "n", "-", "-");
    test(regex_506, 506, "ab\\Z", "b\nac\n", "n", "-", "-");
    test(regex_507, 507, "ab\\z", "b\nac\n", "n", "-", "-");
    test(regex_508, 508, "ab\\$", "b\nac\n", "n", "-", "-");
    test(regex_509, 509, "ab\\Z", "b\nac", "n", "-", "-");
    test(regex_510, 510, "ab\\z", "b\nac", "n", "-", "-");
    test(regex_511, 511, "ab\\$", "b\nac", "n", "-", "-");
    test(regex_512, 512, "ab\\Z", "ca\nb\n", "n", "-", "-");
    test(regex_513, 513, "ab\\z", "ca\nb\n", "n", "-", "-");
    test(regex_514, 514, "ab\\$", "ca\nb\n", "n", "-", "-");
    test(regex_515, 515, "ab\\Z", "b\nca\n", "n", "-", "-");
    test(regex_516, 516, "ab\\z", "b\nca\n", "n", "-", "-");
    test(regex_517, 517, "ab\\$", "b\nca\n", "n", "-", "-");
    test(regex_518, 518, "ab\\Z", "b\nca", "n", "-", "-");
    test(regex_519, 519, "ab\\z", "b\nca", "n", "-", "-");
    test(regex_520, 520, "ab\\$", "b\nca", "n", "-", "-");
    test(regex_521, 521, "ab\\Z", "ca\nb\n", "n", "-", "-");
    test(regex_522, 522, "ab\\z", "ca\nb\n", "n", "-", "-");
    test(regex_523, 523, "ab\\$", "ca\nb\n", "n", "-", "-");
    test(regex_524, 524, "ab\\Z", "b\nca\n", "n", "-", "-");
    test(regex_525, 525, "ab\\z", "b\nca\n", "n", "-", "-");
    test(regex_526, 526, "ab\\$", "b\nca\n", "n", "-", "-");
    test(regex_527, 527, "ab\\Z", "b\nca", "n", "-", "-");
    test(regex_528, 528, "ab\\z", "b\nca", "n", "-", "-");
    test(regex_529, 529, "ab\\$", "b\nca", "n", "-", "-");
    test(regex_530, 530, "abb\\Z", "abb\nb\n", "n", "-", "-");
    test(regex_531, 531, "abb\\z", "abb\nb\n", "n", "-", "-");
    test(regex_532, 532, "abb\\$", "abb\nb\n", "n", "-", "-");
    test(regex_533, 533, "abb\\Z", "b\nabb\n", "y", "$-[0]", "2");
    test(regex_534, 534, "abb\\z", "b\nabb\n", "n", "-", "-");
    test(regex_535, 535, "abb\\$", "b\nabb\n", "y", "$-[0]", "2");
    test(regex_536, 536, "abb\\Z", "b\nabb", "y", "$-[0]", "2");
    test(regex_537, 537, "abb\\z", "b\nabb", "y", "$-[0]", "2");
    test(regex_538, 538, "abb\\$", "b\nabb", "y", "$-[0]", "2");
    test(regex_539, 539, "abb\\Z", "abb\nb\n", "n", "-", "-");
    test(regex_540, 540, "abb\\z", "abb\nb\n", "n", "-", "-");
    test(regex_541, 541, "abb\\$", "abb\nb\n", "y", "$-[0]", "0");
    test(regex_542, 542, "abb\\Z", "b\nabb\n", "y", "$-[0]", "2");
    test(regex_543, 543, "abb\\z", "b\nabb\n", "n", "-", "-");
    test(regex_544, 544, "abb\\$", "b\nabb\n", "y", "$-[0]", "2");
    test(regex_545, 545, "abb\\Z", "b\nabb", "y", "$-[0]", "2");
    test(regex_546, 546, "abb\\z", "b\nabb", "y", "$-[0]", "2");
    test(regex_547, 547, "abb\\$", "b\nabb", "y", "$-[0]", "2");
    test(regex_548, 548, "abb\\Z", "ac\nb\n", "n", "-", "-");
    test(regex_549, 549, "abb\\z", "ac\nb\n", "n", "-", "-");
    test(regex_550, 550, "abb\\$", "ac\nb\n", "n", "-", "-");
    test(regex_551, 551, "abb\\Z", "b\nac\n", "n", "-", "-");
    test(regex_552, 552, "abb\\z", "b\nac\n", "n", "-", "-");
    test(regex_553, 553, "abb\\$", "b\nac\n", "n", "-", "-");
    test(regex_554, 554, "abb\\Z", "b\nac", "n", "-", "-");
    test(regex_555, 555, "abb\\z", "b\nac", "n", "-", "-");
    test(regex_556, 556, "abb\\$", "b\nac", "n", "-", "-");
    test(regex_557, 557, "abb\\Z", "ac\nb\n", "n", "-", "-");
    test(regex_558, 558, "abb\\z", "ac\nb\n", "n", "-", "-");
    test(regex_559, 559, "abb\\$", "ac\nb\n", "n", "-", "-");
    test(regex_560, 560, "abb\\Z", "b\nac\n", "n", "-", "-");
    test(regex_561, 561, "abb\\z", "b\nac\n", "n", "-", "-");
    test(regex_562, 562, "abb\\$", "b\nac\n", "n", "-", "-");
    test(regex_563, 563, "abb\\Z", "b\nac", "n", "-", "-");
    test(regex_564, 564, "abb\\z", "b\nac", "n", "-", "-");
    test(regex_565, 565, "abb\\$", "b\nac", "n", "-", "-");
    test(regex_566, 566, "abb\\Z", "ca\nb\n", "n", "-", "-");
    test(regex_567, 567, "abb\\z", "ca\nb\n", "n", "-", "-");
    test(regex_568, 568, "abb\\$", "ca\nb\n", "n", "-", "-");
    test(regex_569, 569, "abb\\Z", "b\nca\n", "n", "-", "-");
    test(regex_570, 570, "abb\\z", "b\nca\n", "n", "-", "-");
    test(regex_571, 571, "abb\\$", "b\nca\n", "n", "-", "-");
    test(regex_572, 572, "abb\\Z", "b\nca", "n", "-", "-");
    test(regex_573, 573, "abb\\z", "b\nca", "n", "-", "-");
    test(regex_574, 574, "abb\\$", "b\nca", "n", "-", "-");
    test(regex_575, 575, "abb\\Z", "ca\nb\n", "n", "-", "-");
    test(regex_576, 576, "abb\\z", "ca\nb\n", "n", "-", "-");
    test(regex_577, 577, "abb\\$", "ca\nb\n", "n", "-", "-");
    test(regex_578, 578, "abb\\Z", "b\nca\n", "n", "-", "-");
    test(regex_579, 579, "abb\\z", "b\nca\n", "n", "-", "-");
    test(regex_580, 580, "abb\\$", "b\nca\n", "n", "-", "-");
    test(regex_581, 581, "abb\\Z", "b\nca", "n", "-", "-");
    test(regex_582, 582, "abb\\z", "b\nca", "n", "-", "-");
    test(regex_583, 583, "abb\\$", "b\nca", "n", "-", "-");
    test(regex_584, 584, "\\Aa\\$", "a\n\n", "y", "$&", "a");
    test(regex_585, 585, "(?i:.[b].)", "abd", "y", "$&", "abd");
    test(regex_586, 586, "(?i:\\\\N[b]\\\\N)", "abd", "y", "$&", "abd");
    test(regex_587, 587, "\\\\N {1}", "abbbbc", "y", "$&", "a");
    test(regex_588, 588, "\\\\N {1}", "abbbbc", "y", "$-[0]", "0");
    test(regex_589, 589, "\\\\N {1}", "abbbbc", "y", "$+[0]", "1");
    test(regex_590, 590, "\\\\N {3,4}", "abbbbc", "y", "$&", "abbb");
    test(regex_591, 591, "\\\\N {3,4}", "abbbbc", "y", "$-[0]", "0");
    test(regex_592, 592, "\\\\N {3,4}", "abbbbc", "y", "$+[0]", "4");
    test(regex_593, 593, "a\\\\N c", "abc", "y", "$&", "abc");
    test(regex_594, 594, "a\\\\N *c", "axyzc", "y", "$&", "axyzc");
    test(regex_595, 595, "a\\\\N *c", "axyzd", "n", "-", "-");
    test(regex_596, 596, "[a b]", " ", "yS", "$&", " ");
    test(regex_597, 597, "[a b]", " ", "n", "-", "-");
    test(regex_598, 598, "[a\\ b]", " ", "y", "$&", " ");
    test(regex_599, 599, "[ ^ a b ]", "a", "n", "-", "-");
    test(regex_600, 600, "[ ^ a b ]", "b", "n", "-", "-");
    test(regex_601, 601, "[ ^ a b ]", "A", "y", "$&", "A");
    test(regex_602, 602, "(?x:[a b])", " ", "yS", "$&", " ");
    test(regex_603, 603, "(?xx:[a b])", " ", "n", "-", "-");
    test(regex_604, 604, "(?x)[a b]", " ", "yS", "$&", " ");
    test(regex_605, 605, "(?xx)[a b]", " ", "n", "-", "-");
    test(regex_606, 606, "(?-x:[a b])", " ", "yS", "$&", " ");
    test(regex_607, 607, "\\\\N {1}", "abbbbc", "y", "$&", "a");
    test(regex_608, 608, "\\\\N {1}", "abbbbc", "y", "$-[0]", "0");
    test(regex_609, 609, "\\\\N {1}", "abbbbc", "y", "$+[0]", "1");
    test(regex_610, 610, "\\\\N {3,4}", "abbbbc", "y", "$&", "abbb");
    test(regex_611, 611, "\\\\N {3,4}", "abbbbc", "y", "$-[0]", "0");
    test(regex_612, 612, "\\\\N {3,4}", "abbbbc", "y", "$+[0]", "4");
    test(regex_613, 613, "a\\\\N c", "abc", "y", "$&", "abc");
    test(regex_614, 614, "a\\\\N *c", "axyzc", "y", "$&", "axyzc");
    test(regex_615, 615, "a\\\\N *c", "axyzd", "n", "-", "-");
    test(regex_616, 616, "[#]", "a#b", "y", "$&", "#");
    test(regex_617, 617, "[#]b", "a#b", "y", "$&", "#b");
    test(regex_618, 618, "[#]", "a#b", "y", "$&", "#");
    test(regex_619, 619, "[#]b", "a#b", "y", "$&", "#b");
    test(regex_620, 620, "(?'n'foo) \\g{n}", "..foo foo..", "y", "$1", "foo");
    test(regex_621, 621, "(?'n'foo) \\g{ n }", "..foo foo..", "y", "$1", "foo");
    test(regex_622, 622, "(?'n'foo) \\g{n}", "..foo foo..", "yM", "$+{n}", "foo");
    test(regex_623, 623, "(?<n>foo) \\g{n}", "..foo foo..", "y", "$1", "foo");
    test(regex_624, 624, "(?<n>foo) \\g{n}", "..foo foo..", "yM", "$+{n}", "foo");
    test(regex_625, 625, "(?<as>as) (\\w+) \\g{as} (\\w+)", "as easy as pie", "y", "$1-$2-$3", "as-easy-pie");
    test(regex_626, 626, "(?'n'foo) \\k<n>", "..foo foo..", "y", "$1", "foo");
    test(regex_627, 627, "(?'n'foo) \\k<n>", "..foo foo..", "yM", "$+{n}", "foo");
    test(regex_628, 628, "(?<n>foo) \\k'n'", "..foo foo..", "y", "$1", "foo");
    test(regex_629, 629, "(?<n>foo) \\k'n'", "..foo foo..", "yM", "$+{n}", "foo");
    test(regex_630, 630, "(?'a1'foo) \\k'a1'", "..foo foo..", "yM", "$+{a1}", "foo");
    test(regex_631, 631, "(?<a1>foo) \\k<a1>", "..foo foo..", "yM", "$+{a1}", "foo");
    test(regex_632, 632, "(?'_'foo) \\k'_'", "..foo foo..", "yM", "$+{_}", "foo");
    test(regex_633, 633, "(?<_>foo) \\k<_>", "..foo foo..", "yM", "$+{_}", "foo");
    test(regex_634, 634, "(?'_0_'foo) \\k'_0_'", "..foo foo..", "yM", "$+{_0_}", "foo");
    test(regex_635, 635, "(?<_0_>foo) \\k<_0_>", "..foo foo..", "yM", "$+{_0_}", "foo");
    test(regex_636, 636, "(?<as>as) (\\w+) \\k<as> (\\w+)", "as easy as pie", "y", "$1-$2-$3", "as-easy-pie");
    test(regex_637, 637, "(?<as>as) (\\w+) \\k{as} (\\w+)", "as easy as pie", "y", "$1-$2-$3", "as-easy-pie");
    test(regex_638, 638, "(?<as>as) (\\w+) \\k'as' (\\w+)", "as easy as pie", "y", "$1-$2-$3", "as-easy-pie");
    test(regex_639, 639, "(?<as>as) (\\w+) \\k{ as } (\\w+)", "as easy as pie", "y", "$1-$2-$3", "as-easy-pie");
    test(regex_640, 640, "^a(?#xxx){3}c", "aaac", "y", "$&", "aaac");
    test(regex_641, 641, "^a (?#xxx) (?#yyy) {3}c", "aaac", "y", "$&", "aaac");
    test(regex_642, 642, "(?|(a))", "a", "y", "$1-$+", "a-a");
    test(regex_643, 643, "(?|a(.)b|d(.(o).)d|i(.)(.)j)(.)", "d!o!da", "y", "$1-$2-$3", "!o!-o-a");
    test(regex_644, 644, "(?|a(.)b|d(.(o).)d|i(.)(.)j)(.)", "aabc", "y", "$1-$2-$3", "a--c");
    test(regex_645, 645, "(?|a(.)b|d(.(o).)d|i(.)(.)j)(.)", "ixyjp", "y", "$1-$2-$3", "x-y-p");
    test(regex_646, 646, "(?|(?|(a)|(b))|(?|(c)|(d)))", "a", "y", "$1", "a");
    test(regex_647, 647, "(?|(?|(a)|(b))|(?|(c)|(d)))", "b", "y", "$1", "b");
    test(regex_648, 648, "(?|(?|(a)|(b))|(?|(c)|(d)))", "c", "y", "$1", "c");
    test(regex_649, 649, "(?|(?|(a)|(b))|(?|(c)|(d)))", "d", "y", "$1", "d");
    test(regex_650, 650, "(.)(?|(.)(.)x|(.)d)(.)", "abcde", "y", "$1-$2-$3-$4-$5-", "b-c--e--");
    test(regex_651, 651, "(\\\\N)(?|(\\\\N)(\\\\N)x|(\\\\N)d)(\\\\N)", "abcde", "y", "$1-$2-$3-$4-$5-", "b-c--e--");
    test(regex_652, 652, "(?|(?<foo>x))", "x", "yM", "$+{foo}", "x");
    test(regex_653, 653, "(?|(?<foo>x)|(?<bar>y))", "x", "yM", "$+{foo}", "x");
    test(regex_654, 654, "(?|(?<bar>y)|(?<foo>x))", "x", "yM", "$+{foo}", "x");
    test(regex_655, 655, "(?<bar>)(?|(?<foo>x))", "x", "yM", "$+{foo}", "x");
    test(regex_656, 656, "foo\\Kbar", "foobar", "y", "$&", "bar");
    test(regex_657, 657, "foo\\t\\n\\r\\f\\a\\ebar", "foo\t\n\r\f\a\ebar", "y", "$&", "foo\t\n\r\f\a\ebar");
    test(regex_658, 658, "(foo)", "foobar", "y", "$&-$1", "foo-");
    test(regex_659, 659, "(?-n)(foo)(?n)(bar)", "foobar", "y", "$&-$1-$2", "foobar-foo-");
    test(regex_660, 660, "(?-n:(foo)(?n:(bar)))", "foobar", "y", "$&-$1-$2", "foobar-foo-");
    test(regex_661, 661, "foo # Match foo", "foobar", "y", "$&", "foo");
    test(regex_662, 662, "\\x41\\x42", "AB", "y", "$&", "AB");
    test(regex_663, 663, "\\101\\o{102}", "AB", "y", "$&", "AB");
    std::cout << std::endl;
  }

























































































































































































































































































































































































































































































































































































































































































#line 2526 "pure2-regex.cpp2"
  auto test_perl_tests_lookahead::run() const& -> void{
    std::cout << "Running perl_tests_lookahead:" << std::endl;
    test(regex_0, 0, "a(?!b).", "abad", "y", "$&", "ad");
    test(regex_1, 1, "(?=)a", "a", "y", "$&", "a");
    test(regex_2, 2, "a(?=d).", "abad", "y", "$&", "ad");
    test(regex_3, 3, "a(?=c|d).", "abad", "y", "$&", "ad");
    test(regex_4, 4, "^(?:b|a(?=(.)))*\\1", "abc", "y", "$&", "ab");
    test(regex_5, 5, "(?=(a+?))(\\1ab)", "aaab", "y", "$2", "aab");
    test(regex_6, 6, "^(?=(a+?))\\1ab", "aaab", "n", "-", "-");
    test(regex_7, 7, "(?=(a+?))(\\1ab)", "aaab", "y", "$2", "aab");
    test(regex_8, 8, "^(?=(a+?))\\1ab", "aaab", "n", "-", "-");
    test(regex_9, 9, "(.*)(?=c)", "abcd", "y", "$1", "ab");
    test(regex_10, 10, "(.*)(?=c)c", "abcd", "yB", "$1", "ab");
    test(regex_11, 11, "(.*)(?=b|c)", "abcd", "y", "$1", "ab");
    test(regex_12, 12, "(.*)(?=b|c)c", "abcd", "y", "$1", "ab");
    test(regex_13, 13, "(.*)(?=c|b)", "abcd", "y", "$1", "ab");
    test(regex_14, 14, "(.*)(?=c|b)c", "abcd", "y", "$1", "ab");
    test(regex_15, 15, "(.*)(?=[bc])", "abcd", "y", "$1", "ab");
    test(regex_16, 16, "(.*)(?=[bc])c", "abcd", "yB", "$1", "ab");
    test(regex_17, 17, "(.*?)(?=c)", "abcd", "y", "$1", "ab");
    test(regex_18, 18, "(.*?)(?=c)c", "abcd", "yB", "$1", "ab");
    test(regex_19, 19, "(.*?)(?=b|c)", "abcd", "y", "$1", "a");
    test(regex_20, 20, "(.*?)(?=b|c)c", "abcd", "y", "$1", "ab");
    test(regex_21, 21, "(.*?)(?=c|b)", "abcd", "y", "$1", "a");
    test(regex_22, 22, "(.*?)(?=c|b)c", "abcd", "y", "$1", "ab");
    test(regex_23, 23, "(.*?)(?=[bc])", "abcd", "y", "$1", "a");
    test(regex_24, 24, "(.*?)(?=[bc])c", "abcd", "yB", "$1", "ab");
    test(regex_25, 25, "^(a*?)(?!(aa|aaaa)*\\$)(?=a\\z)", "aaaaaaaa", "y", "$1", "aaaaaaa");
    test(regex_26, 26, "a(?!b(?!c))(..)", "abababc", "y", "$1", "bc");
    test(regex_27, 27, "a(?!b(?=a))(..)", "abababc", "y", "$1", "bc");
    test(regex_28, 28, "X(\\w+)(?=\\s)|X(\\w+)", "Xab", "y", "[$1-$2]", "[-ab]");
    test(regex_29, 29, "^a*(?=b)b", "ab", "y", "$&", "ab");
    test(regex_30, 30, "(?!\\A)x", "a\nxb\n", "y", "-", "-");
    test(regex_31, 31, "^(o)(?!.*\\1)", "Oo", "n", "-", "-");
    test(regex_32, 32, ".*a(?!(b|cd)*e).*f", "......abef", "n", "-", "-");
    test(regex_33, 33, "^(a*?)(?!(aa|aaaa)*\\$)", "aaaaaaaaaaaaaaaaaaaa", "y", "$1", "a");
    test(regex_34, 34, "(?!)+?|(.{2,4})", "abcde", "y", "$1", "abcd");
    test(regex_35, 35, "^(a*?)(?!(a{6}|a{5})*\\$)", "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa", "y", "$+[1]", "12");
    test(regex_36, 36, "a(?!b(?!c(?!d(?!e))))...(.)", "abxabcdxabcde", "y", "$1", "e");
    test(regex_37, 37, "X(?!b+(?!(c+)*(?!(c+)*d))).*X", "aXbbbbbbbcccccccccccccaaaX", "y", "-", "-");
    test(regex_38, 38, "((?s).)c(?!.)", "a\nb\nc\n", "y", "$1", "\n");
    test(regex_39, 39, "((?s).)c(?!.)", "a\nb\nc\n", "y", "$1:$&", "\n:\nc");
    test(regex_40, 40, "((?s)b.)c(?!.)", "a\nb\nc\n", "y", "$1", "b\n");
    test(regex_41, 41, "((?s)b.)c(?!.)", "a\nb\nc\n", "y", "$1:$&", "b\n:b\nc");
    test(regex_42, 42, "((?s)b.)c(?!\\\\N)", "a\nb\nc\n", "y", "$1:$&", "b\n:b\nc");
    test(regex_43, 43, "(b.)c(?!\\\\N)", "a\nb\nc\n", "y", "$1:$&", "b\n:b\nc");
    test(regex_44, 44, "a*(?!)", "aaaab", "n", "-", "-");
    std::cout << std::endl;
  }














































#line 2576 "pure2-regex.cpp2"
auto main(int const argc_, char** argv_) -> int{
    auto const args = cpp2::make_args(argc_, argv_); 
#line 2577 "pure2-regex.cpp2"
    CPP2_UFCS(run)(test_perl_tests_general());
    CPP2_UFCS(run)(test_perl_tests_lookahead());
}


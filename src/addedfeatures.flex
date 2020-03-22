
[a-z]+              { yylval.wordValue=new std::string(yytext);  return IDENTIFIER; }
";"                 { yylval.wordValue=new std::string(yytext);  return SEMICOLON; }
"++"                { yylval.wordValue=new std::string(yytext);  return INCREMENT;}
"--"                { yylval.wordValue=new std::string(yytext);  return DECREMENT;}
"<<"                { yylval.wordValue=new std::string(yytext);  return LSHIFT;}
">>"                { yylval.wordValue=new std::string(yytext);  return RSHIFT;}
"<="                { yylval.wordValue=new std::string(yytext);  return LE;}
">="                { yylval.wordValue=new std::string(yytext);  return GE;}
"=="                { yylval.wordValue=new std::string(yytext);  return EQUALITY;}
"!="                { yylval.wordValue=new std::string(yytext);  return NOTEQUAL;}
"->"                { yylval.wordValue=new std::string(yytext);  return ARROW;}
"."                 { yylval.wordValue=new std::string(yytext);  return DOT;}
"||"                { yylval.wordValue=new std::string(yytext);  return LOGICAL_OR;}
"&&"                { yylval.wordValue=new std::string(yytext);  return LOGICAL_AND;}
"+="                { yylval.wordValue=new std::string(yytext);  return PLUSEQUAL;}
"*="                { yylval.wordValue=new std::string(yytext);  return MULEQUAL;}
"/="                { yylval.wordValue=new std::string(yytext);  return DIVEQUAL;}
"%="                { yylval.wordValue=new std::string(yytext);  return MODEQUAL;}
"-="                { yylval.wordValue=new std::string(yytext);  return MINUSEQUAL;}
"&="                { yylval.wordValue=new std::string(yytext);  return ANDEQUAL;}
"<<="               { yylval.wordValue=new std::string(yytext);  return LSHIFTEQUAL;}
">>="               { yylval.wordValue=new std::string(yytext);  return RSHIFTEQUAL;}
"="                 { yylval.wordValue=new std::string(yytext);  return EQUAL;}
"+"                 { yylval.wordValue=new std::string(yytext);  return PLUS;}
"-"                 { yylval.wordValue=new std::string(yytext);  return MINUS;}
"*"                 { yylval.wordValue=new std::string(yytext);  return ASTERISK;}
"/"                 { yylval.wordValue=new std::string(yytext);  return DIV;}
"%"                 { yylval.wordValue=new std::string(yytext);  return MOD;}
"~"                 { yylval.wordValue=new std::string(yytext);  return TILDE;}
"<"                 { yylval.wordValue=new std::string(yytext);  return LT;}
">"                 { yylval.wordValue=new std::string(yytext);  return GT;}
"|="                { yylval.wordValue=new std::string(yytext);  return OREQUAL;}
"^="                { yylval.wordValue=new std::string(yytext);  return XOREQUAL;}
"|"                 { yylval.wordValue=new std::string(yytext);  return BITWISE_OR;}
"&"                 { yylval.wordValue=new std::string(yytext);  return AMPERSAND;}
"!"                 { yylval.wordValue=new std::string(yytext);  return EXCLAMATION;}
"?"                 { yylval.wordValue=new std::string(yytext);  return QUESTION;}
\^                 { yylval.wordValue=new std::string(yytext);  return XOR;}
"typedef"           { yylval.wordValue=new std::string(yytext);  return TYPEEDEF;}
"extern"            { yylval.wordValue=new std::string(yytext);  return EXTERN;}
"static"            { yylval.wordValue=new std::string(yytext);  return STATIC;}
"auto"              { yylval.wordValue=new std::string(yytext);  return AUTO;}
"register"          { yylval.wordValue=new std::string(yytext);  return REGISTER;}
"void"              { yylval.wordValue=new std::string(yytext);  return VOID;}
"char"              { yylval.wordValue=new std::string(yytext);  return CHAR;}
"short"             { yylval.wordValue=new std::string(yytext);  return SHORT;}
"long"              { yylval.wordValue=new std::string(yytext);  return LONG;}
"float"             { yylval.wordValue=new std::string(yytext);  return FLOAT;}
"double"            { yylval.wordValue=new std::string(yytext);  return DOUBLE;}
"signed"            { yylval.wordValue=new std::string(yytext);  return SIGNED;}
"unsigned"          { yylval.wordValue=new std::string(yytext);  return UNSIGNED;}
"struct"            { yylval.wordValue=new std::string(yytext);  return STRUCT;}
"enum"              { yylval.wordValue=new std::string(yytext);  return ENUM;}
"..."               { yylval.wordValue=new std::string(yytext);  return ELLIPSIS;}
"if"                { yylval.wordValue=new std::string(yytext);  return IF;}
"else"              { yylval.wordValue=new std::string(yytext);  return ELSE;}
"switch"            { yylval.wordValue=new std::string(yytext);  return SWITCH;}
"case"              { yylval.wordValue=new std::string(yytext);  return CASE;}
"default"           { yylval.wordValue=new std::string(yytext);  return DEFAULT;}
"for"               { yylval.wordValue=new std::string(yytext);  return FOR;}
"do"                { yylval.wordValue=new std::string(yytext);  return DO;}
"while"             { yylval.wordValue=new std::string(yytext);  return WHILE;}
"continue"          { yylval.wordValue=new std::string(yytext);  return CONTINUE;}
"break"             { yylval.wordValue=new std::string(yytext);  return BREAK;}
"return"            { yylval.wordValue=new std::string(yytext);  return RETURN;}
"("                 { yylval.wordValue=new std::string(yytext);  return LB;}
")"                 { yylval.wordValue=new std::string(yytext);  return RB;}
"["                 { yylval.wordValue=new std::string(yytext);  return LSB;}
"]"                 { yylval.wordValue=new std::string(yytext);  return RSB;}
"{"                 { yylval.wordValue=new std::string(yytext);  return LCB;}
"}"                 { yylval.wordValue=new std::string(yytext);  return RCB;}
":"                 { yylval.wordValue=new std::string(yytext);  return COLON;}
","                 { yylval.wordValue=new std::string(yytext);  return COMMA;}
[']                 { yylval.wordValue=new std::string(yytext);  return QUOTE; }
["]                 { yylval.wordValue=new std::string(yytext);  return DOUBLE_QUOTE; }
\\                  { yylval.wordValue=new std::string(yytext);  return BACKSLASH; }
\x                  { yylval.wordValue=new std::string(yytext);  return HEX_ESCAPE; }


"("                 { return LB; }
")"                 { return RB; }
"{"                 { return LCB; }
"}"                 { return RCB; }
"["                 { return LSB; }
"]"                 { return RSB; }

"\;"                 { ECHO; return SEMICOLON; }

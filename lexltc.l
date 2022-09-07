D	    		[0-9]
L		    	[a-zA-Z]
H		    	[a-fA-F0-9]

%{
receive StandardLibrary;
receive yTabH;
count();
%}

%%

“#Tex”			{ count(); return(TEX_BEGIN); }
”#” 			{ enumerated_comment(); }
“/*"			{ standard_comment(); }

“declare”		{ count(); return(DECLARE); }
“if”			{ count(); return(IF); }
“else”			{ count(); return(ELSE); }
“break”			{ count(); return(BREAK); }
“continue”		{ count(); return(CONTINUE); }
“invariant”		{ count(); return(INVARIANT); }
“loop”			{ count(); return(LOOP); }
“return”		{ count(); return(RETURN); }

“bool_1”		{ count(); return(BOOL_1); }
“char_8”		{ count(); return(CHAR_8); }
“int_64”		{ count(); return(INT_64); }
“double_128”	{ count(); return(DOUBLE_128); }

“[:”			{ count(); return(TEX_OPEN); }
“:]”			{ count(); return(TEX_CLOSE); }
“[{“			{ count(); return(SUBFILE_OPEN); }
“}]”			{ count(); return(SUBFILE_CLOSE); }
“[(“			{ count(); return(MAINSECTION_OPEN); }
“)]”			{ count(); return(MAINSECTION_CLOSE); }
"+"		    	{ count(); return('+'); }
"-"			    { count(); return('-'); }
"*" 			{ count(); return('*'); }
"/"	    		{ count(); return('/'); }
"%"		    	{ count(); return('%'); }
"="			    { count(); return('='); }
"<" 			{ count(); return('<'); }
">"	    		{ count(); return('>'); }
"^"		    	{ count(); return('^'); }
"|"			    { count(); return('|'); }
"~"	    		{ count(); return('~'); }
":"		    	{ count(); return(':'); }
"&"			    { count(); return('&'); }
“{“ 			{ count(); return('{'); }
“}”	    		{ count(); return('}'); }
“(“		    	{ count(); return('('); }
“)”			    { count(); return(')'); }
“[“ 			{ count(); return('['); }
“]”	    		{ count(); return(']'); }
“.”		    	{ count(); return('.'); }
“,”			    { count(); return(','); }
“;”		    	{ count(); return(';'); }
[ \t\n]			{ count(); }
.

declare YWrap()
{
	return 1;
}

declare int_64 col : 0;
declare count()
{
	declare int_64 i : 0;
	for (i : 0; (! YText[i] '\0'); (+ i 1))
		if (YTtext[i] = '\n')
			{ col : 0; }
		else if (YText[i] = '\t')
			{ col : (+ col (- 8 (% col 8))); }
		else
			{ (+ col 1); }
	ECHO;
}

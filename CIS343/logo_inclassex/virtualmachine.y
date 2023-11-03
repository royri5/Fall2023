%{

%}


%union {
        int num
}
%token LEFT BRACK RIGHT_BRACK
%token STRING NUMBER
%token EQUALS LEFT_PAREN RIGHT_PAREN
%token RAM CORES OS USERS COMMA
%type<str> STRING
%type<num> NUMBER



%%

specification_file:     spec_list
                  ;

spec_list:              spec
         |              spec spec_list
         ;

spec:                   hostname expression_list
    ;

hostname:               LEFT_BRACK STRING RIGHT_BRACK
        ;

expression:             

expression_list:             RAM EQUALS NUMBER
          |             CORES EQUALS NUMBER
          |             OS EQUALS STRING
          |             USERS EQUALS user_list
          ;

user_list:              STRING
         |              STRING COMMA user_list
         ;

%%

#include "use_pre.h"

bool _get_bool(char* s){
    int _V;
    printf("input 1/0 %s=",s);
    scanf_s("%d", &_V);
    printf("\n");
    return (bool)_V;
}
int _get_int(char *s){
    int _V;
    printf("input an integer %s=",s);
    scanf_s("%d", &_V);
    printf("\n");
    return _V;
}
float _get_real(char *s){
    float _V;
    printf("input a float %s=",s);
    scanf_s("%f", &_V);
    printf("\n");
    return _V;
}

void _put_bool(bool _V, char *s){
    printf("%s: ", s);
    printf(_V?"true\n":"false\n");
}
void _put_int(int _V, char *s){
    printf("%s: %d\n", s, _V);
}
void _put_real(float _V, char *s){
    printf("%s: %f\n", s, _V);
}
pre_int_ctx_type* pre_int_ctx_new_ctx(){
    pre_int_ctx_type* ctx = (pre_int_ctx_type*)calloc(1, sizeof(pre_int_ctx_type));
    pre_int_ctx_reset(ctx);
    return ctx;
}
void pre_int_ctx_reset(pre_int_ctx_type* ctx){
} 
int pre_int_get(pre_int_ctx_type* ctx){
    return ctx -> _memory;
}
void pre_int_set(int s1, pre_int_ctx_type* ctx){
    ctx -> _memory = s1; 
}
result_ctx_type* new_ctx(){
    result_ctx_type* ctx = (result_ctx_type*)calloc(1, sizeof(result_ctx_type));
    ctx_reset(ctx);
    return ctx;
}
void ctx_reset(result_ctx_type* ctx){
	pre_int_ctx_reset(&ctx->pre_int_ctx_tab[0]);
}
void use_pre(int a,int c,int *b,result_ctx_type* ctx){
int split_1;
split_1 = pre_int_get( &ctx -> pre_int_ctx_tab[0]);
*b=split_1 + c;
pre_int_set(a,&ctx -> pre_int_ctx_tab[0]);
}
int main(){
	int a;
	int c;
	int b;
	result_ctx_type* ctx = new_ctx();
	while(1){
		a = _get_int("a");
		c = _get_int("c");
		use_pre(a,c,&b,ctx);
		_put_int(b,"b");
	}
}

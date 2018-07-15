#ifndef QARROW_K_H
#define QARROW_K_H

extern "C" {

typedef struct k0 {
    signed char m;
    signed char a;
    signed char t;
    char u;
    int r;
    union {
        unsigned char g;
        short h;
        int i;
        long j;
        float e;
        double f;
        char* s;
        struct k0 *k;
        struct {
            long n;
            bool G0[1];
        };
    };
} *K;
typedef struct {
    bool g[16];
} U;
//#define kU(x) ((U*)kG(x))
//#define xU ((U*)xG)
extern K ku(U);
extern K ktn(int, long);
extern K kpn(char*, long);
extern int setm(int);
extern void m9();
extern int khpun(const char*, int, const char*, int);
inline int connect_timeout(const char* host, int port, const char* userpass, int timeout) {
    return khpun(host, port, userpass, timeout);
}
extern int khpu(const char*, int, const char*);
inline int connect(const char* host, int port, const char* userpass) {
    return khpu(host, port, userpass);
}
extern int khp(const char*, int);
extern int okx(K);
extern int ymd(int, int, int);
extern int dj(int);
extern void r0(K);
extern void sd0(int);
extern void sd0x(int d, int f);
extern void kclose(int);
extern char* sn(char*, int);
extern char* ss(char*);
extern K ee(K);
extern K ktj(int, long);
extern K ka(int);
extern K kb(int);
extern K kg(int);
extern K kh(int);
extern K ki(int);
extern K kj(long);
extern K ke(double);
extern K kf(double);
extern K kc(int);
extern K ks(char*);
extern K kd(int);
extern K kz(double);
extern K kt(int);
extern K sd1(int, K(*)(int));
extern K dl(void *f, int);
extern K knk(int, ...);
extern K kp(char*);
extern K ja(K *, void *);
extern K js(K *, char*);
extern K jk(K *, K);
extern K jv(K *k, K);
extern K k(int, const char*, ...);
extern K xT(K);
extern K xD(K, K);
extern K r1(K);
extern K krr(const char*);
extern K orr(const char*);
extern K dot(K, K);
extern K b9(int, K);
extern K d9(K);
}

// nulls(n?) and infinities(w?)
#define nh ((int)0xFFFF8000)
#define wh ((int)0x7FFF)
#define ni ((int)0x80000000)
#define wi ((int)0x7FFFFFFF)
#define nj ((long)0x8000000000000000LL)
#define wj 0x7FFFFFFFFFFFFFFFLL
#if defined(WIN32) || defined(_WIN32)
#define nf (log(-1.0))
#define wf (-log(0.0))
#define finite _finite
extern double log(double);
#else
#define nf (0/0.0)
#define wf (1/0.0)
#define closesocket(x) close(x)
#endif

#endif //QARROW_K_H

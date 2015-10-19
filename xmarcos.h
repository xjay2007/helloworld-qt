#ifndef XMARCOS
#define XMARCOS

#define X_SAFE_DELETE(p)    do{ if (nullptr != p) { delete p; p = nullptr;}}while(0)

#endif // XMARCOS


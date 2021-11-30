//   GreKo chess engine
//   (c) 2002-2020 Vladimir Medvedev <vrm@bk.ru>
//   http://greko.su

#ifndef UTILS_H
#define UTILS_H

#include "types.h"

void out(const string& s);
void out(const stringstream& ss);

string CurrentDateStr();
U32    GetProcTime();
void   Highlight(bool on);
void   InitIO();
bool   InputAvailable();
bool   IsPipe();
bool   Is(const string& cmd, const string& pattern, size_t minLen);
void   Log(const string& s);
U32    Rand32();
U64    Rand64();
U64    Rand64(int bits);
double RandDouble();
void   RandSeed(U64 seed);
void   SleepMillisec(int msec);
void   Split(const string& s, vector<string>& tokens, const string& sep = " ");
string Timestamp();

#endif

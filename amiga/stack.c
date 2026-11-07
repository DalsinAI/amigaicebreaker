/* A Shell gives 4 KB of stack; libnix's startup sets this much up instead.
 * The AmiCradle Team. GPL 2 or later, like IceBreaker. */
unsigned long __stack = 256 * 1024;
static const char version[] __attribute__((used)) = "$VER: IceBreaker 2.2.1 Amiga (06.11.2026)";

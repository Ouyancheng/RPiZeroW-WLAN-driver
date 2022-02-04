#ifndef __SIMPLE_BOOT_H__
#define __SIMPLE_BOOT_H__

// protocol values shared between the pi and unix side.
enum {
    ARMBASE=0x8000, // where program gets linked.  we could send this.

    // the weird numbers are to try to help with debugging
    // when you drop a byte, flip them, corrupt one, etc.
    BOOT_START      = 0xFFFF0000,

    GET_PROG_INFO   = 0x11112222,       // pi sends
    PUT_PROG_INFO   = 0x33334444,       // unix sends

    GET_CODE        = 0x55556666,       // pi sends
    PUT_CODE        = 0x77778888,       // unix sends

    BOOT_SUCCESS    = 0x9999AAAA,       // pi sends on success
    BOOT_ERROR      = 0xBBBBCCCC,       // pi sends on failure.

    PRINT_STRING    = 0xDDDDEEEE,       // pi sends to print a string.

    // error codes from the pi to unix
    BAD_CODE_ADDR   = 0xdeadbeef,
    BAD_CODE_CKSUM  = 0xfeedface,
};

static inline int boot_error(unsigned op) {
    return op == BOOT_ERROR 
    || op == BAD_CODE_ADDR 
    || op == BAD_CODE_CKSUM;
}

// convert boot opcode to a string.
static const char *boot_op(unsigned op) {
    switch(op) {
    case BOOT_START:    return "BOOT_START";
    case GET_PROG_INFO:  return "GET_PROG_INFO";
    case PUT_PROG_INFO:  return "PUT_PROG_INFO";
    case GET_CODE:       return "GET_CODE";
    case PUT_CODE:       return "PUT_CODE";
    case BOOT_SUCCESS:   return "BOOT_SUCCESS";
    case BOOT_ERROR:     return "BOOT_ERROR";
    case PRINT_STRING:   return "PRINT_STRING";
    case BAD_CODE_ADDR:  return "BAD_CODE_ADDR";
    case BAD_CODE_CKSUM: return "BAD_CODE_CKSUM";
    default:             return "UNKNOWN";
    }
}


#endif

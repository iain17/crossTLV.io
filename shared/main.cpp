#include "main.h"

const char* hello() {
    return "Hi there :-)";
}

DrivingLicense parseDrivingLicense() {
    DrivingLicense license;
    license.firstName = "Iain";
    license.lastName = "Munro";
    return license;
}

bool testEncode(void *buffer, size_t buffer_size) {
    Rectangle_t rectangle;
    asn_enc_rval_t ec;
    rectangle.height = 42; /* any random value */
    rectangle.width = 23; /* any random value */
//    uint8_t buffer[128];
//    size_t buf_size = sizeof(buffer);
    asn_enc_rval_t er;
    er = der_encode_to_buffer(&asn_DEF_Rectangle, &rectangle, buffer, buffer_size);
    return er.encoded ==  1;
}

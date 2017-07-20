
#include "patterns.h"

const struct Pattern pat1 = {
	.delay = 1,
	.pattern = {
		0x80,
		0x40}
};

const struct Pattern pat2 = {
	.delay = 1,
	.pattern = {
		0x40,
		0x80}
};

/***/
const struct Pattern pat3a = {
	.delay = 1,
	.pattern = {
		0x80,
		0x00}
 };

const struct Pattern pat3b = {
        .delay = 1,
        .pattern = {
        	0xC0,
		0x00}
};

const struct Pattern pat3c = {
	.delay = 1,
	.pattern = {
		0xC0,
		0x40}
};

const struct Pattern pat3d = {
	.delay = 1,
	.pattern = {
		0xC0,
		0xC0}
};
/***/


const struct Pattern pat3a_inv = {
	.delay = 1,
	.pattern = {
		0xF0^0x80,
		0xF0^0x00}
 };

const struct Pattern pat3b_inv = {
        .delay = 1,
        .pattern = {
        	0xF0^0xC0,
		0xF0^0x00}
};

const struct Pattern pat3c_inv = {
	.delay = 1,
	.pattern = {
		0xF0^0xC0,
		0xF0^0x40}
};

const struct Pattern pat3d_inv = {
	.delay = 1,
	.pattern = {
		0xF0^0xC0,
		0xF0^0xC0}
};

#include "patterns.h"

struct Pattern pat1 = {
	.delay = 1,
	.pattern = {
		0x80,
		0x40}
};

struct Pattern pat2 = {
	.delay = 1,
	.pattern = {
		0x40,
		0x80}
};

struct Pattern pat3a = {
	.delay = 1,
	.pattern = {
		0x80,
		0x00}
 };

struct Pattern pat3b = {
        .delay = 1,
        .pattern = {
        	0xC0,
		0x00}
};

struct Pattern pat3c = {
	.delay = 1,
	.pattern = {
		0xC0,
		0x40}
};

struct Pattern pat3d = {
	.delay = 1,
	.pattern = {
		0xC0,
		0xC0}
};
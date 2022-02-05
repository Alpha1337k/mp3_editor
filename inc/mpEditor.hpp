#ifndef MP_EDITOR_HPP
#define MP_EDITOR_HPP

#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <assert.h>
#include <sys/stat.h>
#include <string.h>
#include <stdio.h>

class idv1_1_header
{
	public:
		std::string title;
		std::string artist;
		std::string album;
		std::string year;
		std::string comment;
		int track;
		int genre;

		idv1_1_header(std::string &file);
};

std::ostream &operator<<(std::ostream &o, const idv1_1_header &h);

#endif
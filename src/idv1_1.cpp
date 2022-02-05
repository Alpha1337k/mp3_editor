#include <mpEditor.hpp>



std::ostream &operator<<(std::ostream &o, const idv1_1_header &h)
{
	o << "title: " << h.title << "$\n";
	o << "artist: " << h.artist << "$\n";
	o << "album: " << h.album << "$\n";
	o << "year: " << h.year << "$\n";
	o << "comment: " << h.comment << "$\n";
	o << "track: " << h.track << "$\n";
	o << "genre: " << h.genre << "$\n";

	return o;
}

idv1_1_header::idv1_1_header(std::string &file)
{
	std::string fr = file.substr(file.length() - 128);

	std::cout << fr << std::endl;
	if (fr.starts_with("TAG") == false)
		assert(0);
	size_t i = 3;
	title = fr.substr(i, 30);
	i += 30;
	artist = fr.substr(i, 30);
	i += 30;
	album = fr.substr(i, 30);
	i += 30;
	year = fr.substr(i, 4);
	i += 4;
	if (fr[125] == 0)
	{
		comment = fr.substr(i, 28);
		i += 28;
		track = fr[i++];
	}
	else
	{
		comment = fr.substr(i, 30);
		i += 30;
		track = -1;
	}
	genre = fr[i++];


	
	std::cout << *this << std::endl;
}

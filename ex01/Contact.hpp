#ifndef CONTACT_HPP
# define CONTACT_HPP

class Contact {

private :
	std::string _first_name;
	std::string _last_name;
	std::string _nickname;
	std::string _phone_number;
	std::string _darkest_secret;

public :
	Contact();
	~Contact();
	void setContact();
	void displayContactColumns(int x) const;
	void displayContactInfos() const;
	bool is_set;
};

#endif
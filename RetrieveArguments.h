#ifndef RETRIEVEARGUMENTS_H
#define RETRIEVEARGUMENTS_H

#include<vector>
#include<string>
#include<tuple>

class RetrieveArguments
{
public:	
	RetrieveArguments() = default;
	RetrieveArguments(const int, char*[]);

	void initilize(const int, char*[]);

	std::vector<std::string> argumentElements() const;

private:
	std::vector<std::string> arguments;
};
#endif

RetrieveArguments::RetrieveArguments(const int amountOfArguments, char* argumentsFromInit[])
{
	for (auto index=1; index!=amountOfArguments; ++index)
		arguments.push_back(std::string(*(argumentsFromInit + index)));
}

void RetrieveArguments::initilize(const int amountOfArguments, char* argumentsFromInit[])
{
	for (auto index=1; index!=amountOfArguments; ++index)
		arguments.push_back(std::string{*(argumentsFromInit + index)});
}
std::vector<std::string> RetrieveArguments::argumentElements() const
{
	return arguments;
}

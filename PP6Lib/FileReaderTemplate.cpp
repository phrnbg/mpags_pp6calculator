#include <sstream>
#include "FileReaderTemplate.hpp"

FileReaderTemplate::FileReaderTemplate(const char* filename)
  : file(filename), line(), failed(false)
{}

FileReaderTemplate::FileReaderTemplate(const std::string& filename)
  : file(filename.c_str()), line(), failed(false)
{}  

bool FileReaderTemplate::isValid() const {
  if ( ! file )
    return false;
  else
    return true;
}

bool FileReaderTemplate::nextLine(){
  getline(file, line);
  if (file.eof())
    return false;
  else 
    return true;
}

void FileReaderTemplate::skip_fields(std::istringstream& ist, const int n) {
  if (n < 1)
    return;
  std::string tmp;
  for(int i = 1; i <= n; ++i) {
    ist >> tmp;
  }
}

void FileReaderTemplate::getField(const int n, C& rval){
     failed = false;
     std::istringstream ist(line);
     this->skip_fields(ist, n-1);
//     C rval;
     ist >> rval;
     if (ist.fail()) {
        failed = true;
     return 0;
     }
     else
     return rval;
}


bool FileReaderTemplate::inputFailed() const {
  return failed;
}

#ifndef FILEREADERTEMPLATE_HPP
#define FILEREADERTEMPLATE_HPP

#include <fstream>
#include <string>


class FileReaderTemplate {
 public:
  FileReaderTemplate(const char* filename);
  FileReaderTemplate(const std::string& filename);

  bool nextLine();

  template <typename C> 
  void getField(const int n, C* rval);


  bool inputFailed() const {return failed;}
  bool isValid() const;

 private:
  void skip_fields(std::istringstream& ist, const int n);
  std::ifstream file;
  std::string line;
  bool failed;
};

template <typename C>
void FileReaderTemplate::getField(const int n, C* rval){
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


#endif

/**
 * @file restclient.h
 * @brief libcurl wrapper for REST calls
 * @author Daniel Schauenberg <d@unwiredcouch.com>
 * @version
 * @date 2010-10-11
 */

#ifndef INCLUDE_RESTCLIENT_H_
#define INCLUDE_RESTCLIENT_H_

#include <curl/curl.h>
//#include <string>
#include <map>
//#include <cstdlib>
//#include <algorithm>

//#include <functional>
//#include <locale>
//#include <cctype>
#include "CryString.h"

class RestClient
{
  public:
    /**
     * public data definitions
     */
    typedef std::map<CryStringT<char>, CryStringT<char>> headermap;

    /** response struct for queries */
    typedef struct
    {
      int code;
      CryStringT<char> body;
      headermap headers;
    } response;
    /** struct used for uploading data */
    typedef struct
    {
      const char* data;
      size_t length;
    } upload_object;

    /** public methods */
    // Auth
    static void clearAuth();
    static void setAuth(const CryStringT<char>& user,const CryStringT<char>& password);
    // HTTP GET
    static response get(const CryStringT<char>& url);
    // HTTP POST
    static response post(const CryStringT<char>& url, const CryStringT<char>& ctype,
                         const CryStringT<char>& data);
    // HTTP PUT
    static response put(const CryStringT<char>& url, const CryStringT<char>& ctype,
                        const CryStringT<char>& data);
    // HTTP DELETE
    static response del(const CryStringT<char>& url);

  private:
    // writedata callback function
    static size_t write_callback(void *ptr, size_t size, size_t nmemb,
                                 void *userdata);

    // header callback function
    static size_t header_callback(void *ptr, size_t size, size_t nmemb,
				  void *userdata);
    // read callback function
    static size_t read_callback(void *ptr, size_t size, size_t nmemb,
                                void *userdata);
    static const char* user_agent;
    static CryStringT<char> user_pass;
};

#endif  // INCLUDE_RESTCLIENT_H_

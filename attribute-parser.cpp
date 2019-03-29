#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <list>

/**
 * By BingLi224
 * 19:45 THA 29/03/2019
 */

using namespace std;

#define FIND_TAG_BEGIN  0
#define FIND_TAG_NAME   1
#define FIND_TAG_NAME_END   2
#define FIND_ATTRIB_OR_TAG_END   3
#define FIND_ATTRIB_END 4
#define FIND_ATTRIB_EQUAL   5
#define FIND_VALUE_BEGIN    6
#define FIND_VALUE_END    7
#define FIND_TAG_CLOSE_NAME    8
#define FIND_TAG_CLOSE_NAME_END    9
#define FIND_TAG_CLOSE_END    10

bool isSpace ( char c ) {
    switch ( c ) {
        case ' ':
        case '\n':
        case '\t':
        case '\r':
            return 1;
        default:
            return 0;
    }
    //return ( c == ' ' || c == '\n' || c == '\t' || c == '\r' );
}

bool isAttrib ( char c ) {
    return
        ( c >= 'a' && c <= 'z' ) ||
        ( c >= 'A' && c <= 'Z' ) ||
        ( c >= '0' && c <= '9' ) ||
        ( c == '-' ) ||
        ( c == '_' );     
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    map <string, map <string, string>> tagMap;

    int N, Q;
    cin >> N >> Q;
    cin.ignore ( 0xff, '\n' );

    list <string> tagTree;
    while ( N -- > 0 ) {
        // parse HRML
        string s;
        std::getline ( cin, s );

        /**
         * parsing mode:
         *  0   find beginning of the tag.
         *          if '<', idxBegin = idx + 1, goto #1.
         *          if \s, skip.
         *          else, error.
         *  1   find the tag name.
         *          if '/',
         *              if idx > idxBegin, error
         *              else, goto #8.
         *          if [a-zA-Z_-], idxBegin = idx, goto #2.
         *          if \s, skip.
         *          else, error
         *  2   find the end of the tag name.
         *          if \s, goto #3.
         *          if '>', add to tag map, goto #0.
         *          else, skip.
         *  3   find attrib name or end of the tag.
         *          if '>', end of the tag, add to tag map, goto #0.
         *          if \S, idxBegin = idx, goto #4.
         *          else, skip.
         *  4   find end of attrib name.
         *          if '=', goto #6.
         *          if \s, get attrib name, goto #5.
         *          else, skip
         *  5   find '=' before value.
         *          if '=' goto #6.
         *          if \S, error.
         *          else, skip
         *  6   find the beginning of the value.
         *          if '"', idxBegin = idx + 1, goto #7.
         *          if \s, skip.
         *          else, error
         *  7   find the end of the value.
         *          if '\', skip next char.
         *          if '"', add attrib/val and goto #3.
         *          else, skip.
         *  8   find the tag name after "</".
         *          if [a-zA-Z_-], goto #9.
         *          if \s, skip.
         *          else, error
         *  9   find the end of tag name after "</".
         *          if \s, goto #10.
         *          if '>', remove tag name from tag tree, goto #0.
         *          else, skip.
         *  10  find the end of the tag.
         *          if '>', remove tag name from tag tree, goto #0.
         *          if \s, skip.
         *          else, error.
         *
         * the end should be #0, #3
         */
        int parseMode = 0;
        string tagName, attribName;

        map <string, string> attribMap;

        int idx = 0;
        int idxBegin = 0, idxEnd = 0;
        while ( idx < s.size ( ) ) {
            char c = s [ idx ];
            switch ( parseMode ) {
            case FIND_TAG_BEGIN: // find '<'
                if ( c == '<' ) {
                    parseMode = FIND_TAG_NAME;
                    idxBegin = idx + 1;
                } else if ( ! isSpace ( c ) ) {
                    // unknown data
                    cout << parseMode << ":: unknown char [" << idx << "] = '" << c << "'" << endl;
                    goto nextLine;
                }
                // else, skip
                break;
            case FIND_TAG_NAME: // find tag name
                if ( c == '/' ) {
                    if ( idx == idxBegin ) {
                        parseMode = FIND_TAG_CLOSE_NAME;
                    } else {
                        // unknown data
                        cout << parseMode << ":: unknown char [" << idx << "] = '" << c << "'" << endl;
                        goto nextLine;
                    }
                } else if ( isAttrib ( c ) ) {
                    idxBegin = idx;
                    idxEnd = 1;
                    parseMode = FIND_TAG_NAME_END;
                } else if ( ! isSpace ( c ) ) {
                    cout << parseMode << ":: unknown char [" << idx << "] = '" << c << "'" << endl;
                    goto nextLine;
                }
                // skip the space
            
                break;
            case FIND_TAG_NAME_END:
                if ( c == '>' ) {
                    // end of tag
                    tagName = s.substr ( idxBegin, idxEnd );
                    tagTree.push_back ( tagName );
                    parseMode = FIND_TAG_BEGIN;
                } else if ( isSpace ( c ) ) {
                    // end of tag name
                    tagName = s.substr ( idxBegin, idxEnd );
                    tagTree.push_back ( tagName );
                    parseMode = FIND_ATTRIB_OR_TAG_END;
                }
                // else, skip
                idxEnd ++;
                break;
            case FIND_ATTRIB_OR_TAG_END:
                if ( c == '>' ) {
                    string fullTagName = "";
                    std::for_each ( tagTree.begin ( ), tagTree.end ( ), [&] ( string tagNode ) mutable {
                        if ( fullTagName.size ( ) > 0 )
                            fullTagName.append ( "." );
                        fullTagName.append ( tagNode );
                    } );
                    tagMap [ fullTagName ] = attribMap;
                    attribMap = { };
                } else if ( ! isSpace ( c ) ) {
                    idxBegin = idx;
                    idxEnd = 0;
                    parseMode = FIND_ATTRIB_END;
                }
                idxEnd ++;
                break;
            case FIND_ATTRIB_END:
                if ( c == '=' ) {
                    attribName = s.substr ( idxBegin, idxEnd );
                    parseMode = FIND_VALUE_BEGIN;
                } else if ( isSpace ( c ) ) {
                    attribName = s.substr ( idxBegin, idxEnd );
                    parseMode = FIND_ATTRIB_EQUAL;
                }
                // else, skip
                idxEnd ++;
                break;
            case FIND_ATTRIB_EQUAL:
                if ( c == '=' ) {
                    parseMode = FIND_VALUE_BEGIN;
                } else if ( ! isSpace ( c ) ) {
                    cout << parseMode << ":: unknown char [" << idx << "] = '" << c << "'" << endl;
                    goto nextLine;
                }
                break;
            case FIND_VALUE_BEGIN:
                if ( c == '"' ) {
                    parseMode = FIND_VALUE_END;
                    idxBegin = idx + 1;
                    idxEnd = 0;
                } else if ( ! isSpace ( c ) ) {
                    cout << parseMode << ":: unknown char [" << idx << "] = '" << c << "'" << endl;
                    goto nextLine;
                }
                // else, skip
                break;
            case FIND_VALUE_END:
                if ( c == '\\' ) {
                    parseMode = FIND_VALUE_END;
                    idx ++;
                    idxEnd ++;
                } else if ( c == '"' ) {
                    parseMode = FIND_ATTRIB_OR_TAG_END;
                    attribMap [ attribName ] = s.substr ( idxBegin, idxEnd );
                }
                // else, skip
                idxEnd ++;
                break;
            case FIND_TAG_CLOSE_NAME:
                if ( isAttrib ( c ) ) {
                    idxBegin = idx;
                    idxEnd = 0;
                    parseMode = FIND_TAG_CLOSE_NAME_END;
                } else if ( ! isSpace ( c ) ) {
                    cout << parseMode << ":: unknown char [" << idx << "] = '" << c << "'" << endl;
                    goto nextLine;
                }
                // skip the space
                break;
            case FIND_TAG_CLOSE_NAME_END:
                if ( c == '>' || isSpace ( c ) ) {
                    // remove the tag
                    tagName = s.substr ( idxBegin, idxEnd );
                    if ( tagName.compare ( tagTree.back ( ) ) ) {
                        // remove the last tag
                        tagTree.pop_back ( );
                    } else {
                        cout << parseMode << ":: found tag name [" << idx << "] \"" << tagName << "\" is not as tag tree leaf \"" << tagTree.back ( ) << "\"." << endl;
                        goto nextLine;
                    }

                    if ( c == '>' ) {
                        parseMode = FIND_TAG_BEGIN;
                    } else {
                        parseMode = FIND_TAG_CLOSE_END;
                    }
                }
                // else, skip
                idxEnd ++;
                break;
            case FIND_TAG_CLOSE_END:
                if ( c == '>' ) {
                    parseMode = FIND_TAG_BEGIN;
                } else if ( ! isSpace ( c ) ) {
                    cout << parseMode << ":: unknown char [" << idx << "] = '" << c << "'" << endl;
                    goto nextLine;
                }
                // else, skip
                break;
            default:
                goto nextLine;
            } // switch: parsing mode
            idx ++;
        } // while: get next char in current line

nextLine:;
    } // while: get HRML line

    while ( Q -- > 0 ) {
        // get the output requests
        string query;

        std::getline ( cin, query );

        int idxAttrib = query.find ( "~" );
        string tagName = query.substr ( 0, idxAttrib );
        string attribName = query.substr ( idxAttrib + 1, query.size ( ) - idxAttrib - 1 );
        
        try {
            cout << tagMap.at ( tagName ).at ( attribName ) << endl;
        } catch ( out_of_range & e ) {
            cout << "Not Found!" << endl;
        }
    }
    return 0;
}

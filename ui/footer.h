// Compact shared footer for every page.
#pragma once
#include <string>
#include "site_data.h"
#include "layout.h"
using namespace std;

string footerCopyright() { return "© " + YEAR + " " + FULL_NAME; }

string footerHtml() {
    string s = "</main>\n<footer class=\"footer\">\n<div class=\"wrap footer-inner\">\n";
    s += "<div class=\"footer-primary\">\n";
    s += "<a class=\"logo footer-logo\" href=\"index.html\"><span class=\"logo-mark\">" + LOGO_SVG + "</span><span>" + SITE_NAME + "</span></a>\n";
    s += "<nav class=\"footer-nav\" aria-label=\"Footer navigation\"><ul>\n";
    for (int i = 0; i < (int)navLinks.size(); i++)
        s += "<li><a href=\"" + navLinks[i].file + "\">" + navLinks[i].label + "</a></li>\n";
    s += "</ul></nav>\n";
    s += "<div class=\"footer-actions\"><a href=\"mailto:" + EMAIL + "\">Email</a><a href=\"" + assetUrl(CV_FILE) + "\" download>CV <span aria-hidden=\"true\">↓</span></a></div>\n";
    s += "</div>\n<div class=\"footer-bottom\"><span>" + footerCopyright() + "</span><span>" + LOCATION + "</span><a class=\"to-top\" href=\"#top\">Back to top ↑</a></div>\n";
    s += "</div>\n</footer>\n</body>\n</html>\n";
    return s;
}

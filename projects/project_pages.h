// =====================================================
//  project_pages.h  -  THE PAGES THAT SHOW THE PROJECTS
//  - projectTile(): the small card (home page + projects page)
//  - projectsPage(): the page with all the projects
//  - projectPage(i): the detail page of one project
//  The projects themselves come from the projects folder.
// =====================================================
#pragma once
#include <string>
#include "project_loader.h"
#include "../ui/layout.h"
#include "../ui/footer.h"
using namespace std;

// one project tile (used on home and projects page)
string projectTile(const Project& p) {
    string s = "<a class=\"tile\" href=\"project-" + p.slug + ".html\">\n";
    if (!p.photos.empty()) {
        s += "<div class=\"tile-img\"><img src=\"" + projectAssetUrl(p, p.photos[0].file) + "\" alt=\"" + p.title + "\" loading=\"eager\"></div>\n";
    } else {
        string n = p.order < 10 ? "0" + to_string(p.order) : to_string(p.order);
        s += "<div class=\"tile-cover\"><span class=\"tile-index\">PROJECT NOTE / " + n + "</span><span class=\"tile-cat\">" + p.category + "</span><h3>" + p.title + "</h3><span class=\"tile-cover-footer\">" + p.footerTitle + " <b aria-hidden=\"true\">↗</b></span></div>\n";
    }
    s += "<div class=\"tile-body\"><p>" + p.summary + "</p><span class=\"more\">Read project note <b aria-hidden=\"true\">→</b></span></div>\n</a>\n";
    return s;
}

// ---------------------- PROJECTS PAGE ----------------------
string projectsPage() {
    string s = startPage("Projects", "projects.html");
    s += pageTitle("Selected projects", "Here are two projects I have documented so far: a wheelchair capstone and a smart farm concept built around the ATmega328P.");
    s += "<section class=\"wrap section\">\n<div class=\"projects-grid\">\n";
    for (int i = 0; i < (int)projects.size(); i++) {
        s += projectTile(projects[i]);
    }
    s += "</div>\n</section>\n";
    s += ctaHtml();
    s += footerHtml();
    return s;
}

// ---------------------- ONE PROJECT PAGE ----------------------
// i = number of the project in the list (the order of the files in the projects folder)
string projectPage(int i) {
    const Project& p = projects[i];
    string s = startPage(p.title, "projects.html");

    s += "<section class=\"wrap page-hero\">\n<a class=\"crumb\" href=\"projects.html\">&larr; Back to all projects</a>\n";
    s += "<h1>" + p.title + "</h1>\n<p>" + p.summary + "</p>\n</section>\n";

    s += "<section class=\"wrap section\">\n<div class=\"detail\">\n<div>\n";

    // Render supplied photos or clearly labeled demo illustrations from each project file.
    if (!p.photos.empty()) {
        if (!p.imageNote.empty()) s += "<p class=\"image-note\">" + p.imageNote + "</p>\n";
        s += "<div class=\"gallery\" id=\"gallery\">\n";
        for (int k = 0; k < (int)p.photos.size(); k++) {
            s += "<figure><a href=\"#pic-" + to_string(k) + "\"><img src=\"" + projectAssetUrl(p, p.photos[k].file) + "\" alt=\"" + p.photos[k].caption + "\" loading=\"eager\">";
            s += "<figcaption>" + p.photos[k].caption + "</figcaption></a></figure>\n";
        }
        s += "</div>\n";
        for (int k = 0; k < (int)p.photos.size(); k++)
            s += "<a class=\"lightbox\" id=\"pic-" + to_string(k) + "\" href=\"#gallery\"><div><img src=\"" + projectAssetUrl(p, p.photos[k].file) + "\" alt=\"\"><p>" + p.photos[k].caption + "</p></div></a>\n";
    }

    // text
    s += "<div class=\"text-block\">\n<h2>How the project took shape</h2>\n";
    for (int k = 0; k < (int)p.details.size(); k++) {
        s += "<p>" + p.details[k] + "</p>\n";
    }
    s += "<h2>Project focus</h2>\n<ul class=\"check\">\n";
    for (int k = 0; k < (int)p.features.size(); k++) {
        s += "<li>" + p.features[k] + "</li>\n";
    }
    s += "</ul>\n</div>\n</div>\n";

    // side box
    s += "<aside class=\"card side-box reveal\">\n<h3>Type</h3>\n<div class=\"tags\"><span class=\"tag\">" + p.category + "</span></div>\n";
    s += "<h3>Tools and topics</h3>\n<div class=\"tags\">";
    for (int k = 0; k < (int)p.tools.size(); k++) {
        s += "<span class=\"tag\">" + p.tools[k] + "</span>";
    }
    s += "</div>\n<h3>Made by</h3>\n<p>" + FULL_NAME + "</p>\n</aside>\n";
    s += "</div>\n";

    // Linear project navigation avoids wrapping to the same project twice.
    int total = (int)projects.size();
    if (total > 1 && (i > 0 || i < total - 1)) {
        s += "<nav class=\"pager\" aria-label=\"Project navigation\">\n";
        if (i > 0)
            s += "<a href=\"project-" + projects[i-1].slug + ".html\"><small>&larr; Previous project</small>" + projects[i-1].title + "</a>\n";
        if (i < total - 1)
            s += "<a class=\"next\" href=\"project-" + projects[i+1].slug + ".html\"><small>Next project &rarr;</small>" + projects[i+1].title + "</a>\n";
        s += "</nav>\n";
    }
    s += "</section>\n";

    s += footerHtml();
    return s;
}

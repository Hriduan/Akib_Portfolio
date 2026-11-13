// =====================================================
//  pages.h  -  ONE FUNCTION FOR EACH NORMAL PAGE
//  Home, About, Experience and Contact.
//  (the Projects page and the project pages are in
//   projects/project_pages.h)
//  Every function returns the full text of one page.
// =====================================================
#pragma once
#include <string>
#include "site_data.h"
#include "layout.h"
#include "footer.h"
#include "../projects/project_pages.h"
using namespace std;

// ---------------------- HOME PAGE ----------------------
string homePage() {
    string s = startPage("Home", "index.html");
    s += "<section class=\"wrap hero\">\n<div class=\"hero-copy\">\n";
    s += "<p class=\"hero-hi\">EEE · AIUB · DHAKA</p>\n";
    s += "<h1>" + FULL_NAME + "<span class=\"hero-period\">.</span></h1>\n";
    s += "<p class=\"hero-role\">Final-year Electrical and Electronic Engineering student <span>· Expected 2027</span></p>\n";
    s += "<p class=\"hero-text\">" + TAGLINE + "</p>\n";
    s += "<div class=\"btn-row\"><a class=\"btn primary\" href=\"projects.html\">Explore projects <span aria-hidden=\"true\">→</span></a>";
    s += "<a class=\"btn\" href=\"resume.html\">View CV</a></div>\n";
    s += "<div class=\"hero-meta\"><span><b>Focus</b> Digital design &amp; embedded systems</span><span><b>Based in</b> " + LOCATION + "</span></div>\n";
    s += "</div>\n<div class=\"photo-wrap\"><div class=\"photo-frame\"><img src=\"" + assetUrl(PROFILE_PHOTO) + "\" alt=\"Portrait of " + FULL_NAME + "\" fetchpriority=\"high\"></div>";
    s += "<div class=\"photo-badge\">" + BADGE + "</div></div>\n</section>\n";

    s += "<section class=\"wrap intro-feature\" aria-labelledby=\"intro-title\">\n";
    s += "<div class=\"intro-feature-copy\"><p class=\"section-kicker\">Meet Akib</p><h2 id=\"intro-title\">A short hello, before the project notes.</h2>";
    s += "<p>In this introduction I share a little about my engineering studies and how I like to work through a project.</p>";
    s += "<div class=\"intro-feature-meta\"><span>EEE · AIUB</span><span>Dhaka, Bangladesh</span></div></div>\n";
    s += "<div class=\"intro-feature-player\"><div class=\"intro-player-heading\"><span>PERSONAL INTRODUCTION</span><span>VIDEO / AUDIO</span></div>";
    s += "<video controls playsinline preload=\"metadata\" poster=\"assets/akib-rahman.jpg\" aria-label=\"Introduction video from Akib Rahman\">";
    s += "<source src=\"assets/Akib_Rahman_Intro.mp4\" type=\"video/mp4\">";
    s += "<p>Your browser does not support this video. <a href=\"assets/Akib_Rahman_Intro.mp4\">Download the introduction video</a>.</p></video>";
    s += "<p class=\"intro-player-note\">Use the video controls to play and adjust the sound.</p></div>\n</section>\n";

    s += "<section class=\"wrap section\" aria-labelledby=\"snapshot-title\"><div class=\"snapshot\">\n";
    s += "<div class=\"snapshot-copy\"><p class=\"section-kicker\">A quick introduction</p><h2 id=\"snapshot-title\">Curious about what happens between an idea and a working system.</h2>";
    s += "<p>My capstone combines machine learning with Raspberry Pi 5 and ESP32-based hardware. I am interested in how careful engineering choices make technology useful in the real world.</p>";
    s += "<a class=\"text-link\" href=\"about.html\">More about my approach <span aria-hidden=\"true\">→</span></a></div>\n";
    s += "<div class=\"snapshot-stats\">\n";
    for (int i = 0; i < (int)stats.size(); i++) {
        string value = replaceAll(stats[i].value, "{projects}", to_string(projects.size()));
        string label = replaceAll(stats[i].label, "{projects}", to_string(projects.size()));
        s += "<div class=\"snapshot-stat\"><b>" + value + "</b><span>" + label + "</span></div>\n";
    }
    s += "</div></div></section>\n";

    s += "<section class=\"wrap section interests-section\"><div class=\"section-head\"><p class=\"section-kicker\">What I am exploring</p><h2>Areas that keep me curious</h2><p>Interests shaped by my coursework, team projects and the questions I want to keep pursuing.</p></div><div class=\"grid\">\n";
    for (int i = 0; i < (int)interests.size(); i++) {
        s += "<article class=\"card interest\"><span class=\"interest-index\">0" + to_string(i+1) + "</span><h3>" + interests[i].name + "</h3><p>" + interests[i].text + "</p></article>\n";
    }
    s += "</div></section>\n";

    s += "<section class=\"wrap section\"><div class=\"section-head section-head-row\"><div><p class=\"section-kicker\">Selected work</p><h2>Projects with purpose</h2><p>A mobility-focused capstone and a microcontroller-based smart farm system.</p></div><a class=\"text-link\" href=\"projects.html\">All projects <span aria-hidden=\"true\">→</span></a></div><div class=\"projects-grid\">\n";
    for (int i = 0; i < 4 && i < (int)projects.size(); i++) s += projectTile(projects[i]);
    s += "</div></section>\n";
    s += "<div class=\"section\">\n" + ctaHtml() + "</div>\n";
    s += footerHtml();
    return s;
}

// ---------------------- RESUME PAGE ----------------------
string resumePage() {
    string s = startPage("Resume", "resume.html");
    s += pageTitle("Curriculum vitae", "A focused overview of my education, technical interests and academic project work.");
    s += "<section class=\"wrap section resume-layout\">\n<div class=\"card resume-copy\">";
    s += "<p class=\"resume-kicker\">" + ROLE + " · " + LOCATION + "</p>";
    s += "<h2>" + FULL_NAME + "</h2><p>Download the concise, portfolio-ready CV or review it below.</p>";
    s += "<div class=\"resume-actions btn-row\"><a class=\"btn primary\" href=\"" + assetUrl(CV_FILE) + "\" download>Download CV <span aria-hidden=\"true\">↓</span></a>";
    s += "<a class=\"btn\" href=\"contact.html\">Contact</a></div></div>\n";
    s += "<div class=\"card resume-viewer\"><a class=\"resume-preview-link\" href=\"" + assetUrl(CV_FILE) + "\" target=\"_blank\" rel=\"noopener\" aria-label=\"Open the full CV PDF\"><img class=\"resume-preview\" src=\"" + assetUrl("Akib_Rahman_CV_preview.jpg") + "\" alt=\"Preview of Akib Rahman’s CV. Open the PDF for selectable text.\"></a><p class=\"resume-fallback\">Open the preview to view the full PDF or <a href=\"" + assetUrl(CV_FILE) + "\" download>download the CV</a>.</p></div>\n</section>\n";
    s += ctaHtml();
    s += footerHtml();
    return s;
}

// ---------------------- ABOUT PAGE ----------------------
string aboutPage() {
    string s = startPage("About", "about.html");
    s += pageTitle("About Akib", "The person, projects and questions behind the portfolio.");
    s += "<section class=\"wrap section\">\n<div class=\"about\">\n";
    s += "<div class=\"photo-wrap about-photo\"><div class=\"photo-frame\"><img src=\"" + assetUrl(PROFILE_PHOTO) + "\" alt=\"Portrait of " + FULL_NAME + "\" loading=\"lazy\"></div><p class=\"photo-caption\">" + LOCATION + " · " + UNI_SHORT + "</p></div>\n";
    s += "<div class=\"about-copy\"><p class=\"section-kicker\">A little context</p>";
    for (int i = 0; i < (int)aboutParagraphs.size(); i++) s += "<p>" + aboutParagraphs[i] + "</p>";
    s += "<div class=\"tags\"><span class=\"tag\">" + LOCATION + "</span><span class=\"tag\">" + UNI_SHORT + "</span><span class=\"tag\">" + FIELD_SHORT + "</span></div></div>\n";
    s += "</div>\n</section>\n";

    s += "<section class=\"wrap section\"><div class=\"section-head\"><p class=\"section-kicker\">Interests</p><h2>What I want to understand better</h2></div><div class=\"grid\">\n";
    for (int i = 0; i < (int)interests.size(); i++) {
        s += "<article class=\"card interest\"><span class=\"interest-index\">0" + to_string(i+1) + "</span><h3>" + interests[i].name + "</h3><p>" + interests[i].text + "</p></article>\n";
    }
    s += "</div></section>\n";

    s += "<section class=\"wrap section\"><div class=\"section-head\"><p class=\"section-kicker\">Education</p><h2>Learning in progress</h2><p>My academic path so far, from secondary study to my current degree.</p></div><div class=\"timeline\">\n";
    for (int i = 0; i < (int)education.size(); i++) {
        const Education& e = education[i];
        s += "<article class=\"card t-item\"><small>" + e.year + "</small><h3>" + e.school + "</h3>";
        s += "<p>" + e.degree + "</p><p>" + e.place + "</p><span class=\"tag\">" + e.result + "</span>";
        if (i == 0 && !COURSEWORK.empty()) s += "<p class=\"coursework\">" + COURSEWORK + "</p>";
        s += "</article>\n";
    }
    s += "</div></section>\n";
    s += ctaHtml();
    s += footerHtml();
    return s;
}

// ---------------------- EXPERIENCE PAGE ----------------------
string experiencePage() {
    string s = startPage("Experience", "experience.html");
    s += pageTitle("Experience & collaboration", "Project teamwork, technical communication and the skills I am building.");
    s += "<section class=\"wrap section experience-layout\"><div class=\"section-head\"><p class=\"section-kicker\">Project practice</p><h2>Learning by working with others</h2><p>Project practice built through collaboration, implementation and technical presentation.</p></div>\n<div class=\"timeline\">\n";
    for (int i = 0; i < (int)experiences.size(); i++) {
        s += "<article class=\"card t-item\"><span class=\"tag\">" + experiences[i].tag + "</span><h3>" + experiences[i].title + "</h3><p>" + experiences[i].text + "</p></article>\n";
    }
    s += "</div></section>\n";
    s += "<section class=\"wrap section\"><div class=\"section-head\"><p class=\"section-kicker\">Technical toolkit</p><h2>Skills and working knowledge</h2><p>A practical toolkit across engineering fundamentals, programming and embedded platforms.</p></div><div class=\"grid\">\n";
    for (int i = 0; i < (int)skills.size(); i++) {
        s += "<article class=\"card skill-card\"><h3>" + skills[i].title + "</h3><div class=\"tags\">";
        for (int k = 0; k < (int)skills[i].items.size(); k++) s += "<span class=\"tag\">" + skills[i].items[k] + "</span>";
        s += "</div></article>\n";
    }
    s += "</div></section>\n<div class=\"section\">\n" + ctaHtml() + "</div>\n";
    s += footerHtml();
    return s;
}

// ---------------------- CONTACT PAGE ----------------------
string contactPage() {
    string s = startPage("Contact", "contact.html");
    s += pageTitle("Get in touch", "For questions about my work, engineering studies or internship opportunities, email is the best way to reach me.");
    s += "<section class=\"wrap section contact-section\"><div class=\"contact-intro\"><p class=\"section-kicker\">Contact details</p><h2>Start a conversation.</h2><p>I welcome thoughtful questions about the projects and topics on this site.</p>";
    s += "<a class=\"btn primary\" href=\"mailto:" + EMAIL + "?subject=Hello%20Akib\">Email Akib <span aria-hidden=\"true\">↗</span></a></div>\n";
    s += "<div class=\"contact-list\">\n";
    s += "<a class=\"info-link\" href=\"mailto:" + EMAIL + "\"><span class=\"ico\">@</span><span><small>Email</small><strong>" + EMAIL + "</strong></span><span class=\"info-arrow\">↗</span></a>\n";
    s += "<a class=\"info-link\" href=\"tel:" + telHref() + "\"><span class=\"ico\">Ph</span><span><small>Phone</small><strong>" + PHONE + "</strong></span><span class=\"info-arrow\">↗</span></a>\n";
    s += "<div class=\"info-link\"><span class=\"ico\">Loc</span><span><small>Location</small><strong>" + LOCATION + "</strong></span></div>\n";
    if (!LINKEDIN.empty()) s += "<a class=\"info-link\" href=\"" + LINKEDIN + "\" target=\"_blank\" rel=\"noopener\"><span class=\"ico\">in</span><span><small>LinkedIn</small><strong>Professional profile</strong></span><span class=\"info-arrow\">↗</span></a>\n";
    s += "<div class=\"cv-card\"><div><p class=\"section-kicker\">A little more detail</p><h3>View my CV</h3><p>Education, technical skills and selected academic project experience.</p></div><a class=\"btn\" href=\"resume.html\">Open CV page <span aria-hidden=\"true\">→</span></a></div>\n";
    s += "</div></section>\n";
    s += footerHtml();
    return s;
}

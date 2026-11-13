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
    s += "<h1>" + FULL_NAME + "<span class=\"hero-period\">.</span></h1>\n";
    s += "<p class=\"hero-role\">Final-year Electrical and Electronic Engineering student <span>· Expected 2027</span></p>\n";
    s += "<p class=\"hero-text\">" + TAGLINE + "</p>\n";
    s += "<div class=\"btn-row\"><a class=\"btn primary\" href=\"projects.html\">Explore projects <span aria-hidden=\"true\">→</span></a>";
    s += "<a class=\"btn\" href=\"resume.html\">View CV</a></div>\n";
    s += "</div>\n<div class=\"photo-wrap\"><div class=\"photo-frame\"><img src=\"" + assetUrl(PROFILE_PHOTO) + "\" alt=\"Portrait of " + FULL_NAME + "\" fetchpriority=\"high\"></div>";
    s += "</div>\n</section>\n";

    s += "<section class=\"wrap intro-feature\" aria-labelledby=\"intro-title\">\n";
    s += "<div class=\"intro-feature-copy\"><p class=\"section-kicker\">Meet Akib</p><h2 id=\"intro-title\">A little about me, in my own words.</h2>";
    s += "<p>I talk about what drew me to engineering and what I enjoy about building things.</p></div>\n";
    s += "<div class=\"intro-feature-player\"><div class=\"intro-player-heading\"><span>PERSONAL INTRODUCTION</span><span>VIDEO / AUDIO</span></div>";
    s += "<video controls playsinline preload=\"metadata\" poster=\"assets/akib-rahman.jpg\" aria-label=\"Introduction video from Akib Rahman\">";
    s += "<source src=\"assets/Akib_Rahman_Intro.mp4\" type=\"video/mp4\">";
    s += "<p>Your browser does not support this video. <a href=\"assets/Akib_Rahman_Intro.mp4\">Download the introduction video</a>.</p></video>";
    s += "<p class=\"intro-player-note\">Use the video controls to play and adjust the sound.</p></div>\n</section>\n";

    s += "<section class=\"wrap section\" aria-labelledby=\"snapshot-title\"><div class=\"snapshot\">\n";
    s += "<div class=\"snapshot-copy\"><p class=\"section-kicker\">A quick introduction</p><h2 id=\"snapshot-title\">I enjoy figuring out how an idea can become a working system.</h2>";
    s += "<p>My capstone brings machine learning together with Raspberry Pi 5 and ESP32-based hardware. It has made me more interested in the choices that help engineering solve practical problems.</p>";
    s += "<a class=\"text-link\" href=\"about.html\">More about my approach <span aria-hidden=\"true\">→</span></a></div>\n";
    s += "<div class=\"snapshot-stats\">\n";
    for (int i = 0; i < (int)stats.size(); i++) {
        string value = replaceAll(stats[i].value, "{projects}", to_string(projects.size()));
        string label = replaceAll(stats[i].label, "{projects}", to_string(projects.size()));
        s += "<div class=\"snapshot-stat\"><b>" + value + "</b><span>" + label + "</span></div>\n";
    }
    s += "</div></div></section>\n";

    s += "<section class=\"wrap section interests-section\"><div class=\"section-head\"><p class=\"section-kicker\">What I am exploring</p><h2>Areas that keep me curious</h2><p>These interests have grown through coursework and team projects. They are also the questions I want to keep exploring.</p></div><div class=\"grid\">\n";
    for (int i = 0; i < (int)interests.size(); i++) {
        s += "<article class=\"card interest\"><span class=\"interest-index\">0" + to_string(i+1) + "</span><h3>" + interests[i].name + "</h3><p>" + interests[i].text + "</p></article>\n";
    }
    s += "</div></section>\n";

    s += "<section class=\"wrap section\"><div class=\"section-head section-head-row\"><div><p class=\"section-kicker\">Selected work</p><h2>Projects with purpose</h2><p>A wheelchair capstone and a smart farm project built around the ATmega328P. Both have taught me something about working through engineering challenges with a team.</p></div><a class=\"text-link\" href=\"projects.html\">All projects <span aria-hidden=\"true\">→</span></a></div><div class=\"projects-grid\">\n";
    for (int i = 0; i < 4 && i < (int)projects.size(); i++) s += projectTile(projects[i]);
    s += "</div></section>\n";
    s += "<div class=\"section\">\n" + ctaHtml() + "</div>\n";
    s += footerHtml();
    return s;
}

// ---------------------- RESUME PAGE ----------------------
string resumePage() {
    string s = startPage("Resume", "resume.html");
    s += pageTitle("Curriculum vitae", "A quick overview of my education and engineering projects.");
    s += "<section class=\"wrap section resume-layout\">\n<div class=\"card resume-copy\">";
    s += "<p class=\"resume-kicker\">" + ROLE + " · " + LOCATION + "</p>";
    s += "<h2>" + FULL_NAME + "</h2><p>Download my CV or take a look at the preview below.</p>";
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
    s += pageTitle("About Akib", "I study electrical and electronic engineering and enjoy learning by building things with a team.");
    s += "<section class=\"wrap section\">\n<div class=\"about\">\n";
    s += "<div class=\"photo-wrap about-photo\"><div class=\"photo-frame\"><img src=\"" + assetUrl(PROFILE_PHOTO) + "\" alt=\"Portrait of " + FULL_NAME + "\" loading=\"lazy\"></div></div>\n";
    s += "<div class=\"about-copy\"><p class=\"section-kicker\">A little context</p>";
    for (int i = 0; i < (int)aboutParagraphs.size(); i++) s += "<p>" + aboutParagraphs[i] + "</p>";
    s += "</div>\n";
    s += "</div>\n</section>\n";

    s += "<section class=\"wrap section\"><div class=\"section-head\"><p class=\"section-kicker\">Interests</p><h2>What I am curious about</h2></div><div class=\"grid\">\n";
    for (int i = 0; i < (int)interests.size(); i++) {
        s += "<article class=\"card interest\"><span class=\"interest-index\">0" + to_string(i+1) + "</span><h3>" + interests[i].name + "</h3><p>" + interests[i].text + "</p></article>\n";
    }
    s += "</div></section>\n";

    s += "<section class=\"wrap section\"><div class=\"section-head\"><p class=\"section-kicker\">Education</p><h2>Learning in progress</h2><p>A few milestones from school through my current degree.</p></div><div class=\"timeline\">\n";
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
    s += pageTitle("Experience & collaboration", "A look at the team projects and presentations that have shaped my engineering experience.");
    s += "<section class=\"wrap section experience-layout\"><div class=\"section-head\"><p class=\"section-kicker\">Project practice</p><h2>What project work has taught me</h2><p>Working with a team has been a big part of my learning so far. Here are a few examples.</p></div>\n<div class=\"timeline\">\n";
    for (int i = 0; i < (int)experiences.size(); i++) {
        s += "<article class=\"card t-item\"><span class=\"tag\">" + experiences[i].tag + "</span><h3>" + experiences[i].title + "</h3><p>" + experiences[i].text + "</p></article>\n";
    }
    s += "</div></section>\n";
    s += "<section class=\"wrap section\"><div class=\"section-head\"><p class=\"section-kicker\">Technical toolkit</p><h2>Tools and skills I use</h2><p>My current skills range from circuit fundamentals to programming and embedded platforms.</p></div><div class=\"grid\">\n";
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
    s += pageTitle("Get in touch", "Have a question about a project or want to talk about my studies? Email is the easiest way to reach me.");
    s += "<section class=\"wrap section contact-section\"><div class=\"contact-intro\"><p class=\"section-kicker\">Contact details</p><h2>Start a conversation.</h2><p>If you would like to talk about a project or an internship opportunity I would be glad to hear from you.</p>";
    s += "<a class=\"btn primary\" href=\"mailto:" + EMAIL + "?subject=Hello%20Akib\">Email Akib <span aria-hidden=\"true\">↗</span></a></div>\n";
    s += "<div class=\"contact-list\">\n";
    s += "<a class=\"info-link\" href=\"mailto:" + EMAIL + "\"><span class=\"ico\">@</span><span><small>Email</small><strong>" + EMAIL + "</strong></span><span class=\"info-arrow\">↗</span></a>\n";
    s += "<a class=\"info-link\" href=\"tel:" + telHref() + "\"><span class=\"ico\">Ph</span><span><small>Phone</small><strong>" + PHONE + "</strong></span><span class=\"info-arrow\">↗</span></a>\n";
    s += "<div class=\"info-link\"><span class=\"ico\">Loc</span><span><small>Location</small><strong>" + LOCATION + "</strong></span></div>\n";
    if (!LINKEDIN.empty()) s += "<a class=\"info-link\" href=\"" + LINKEDIN + "\" target=\"_blank\" rel=\"noopener\"><span class=\"ico\">in</span><span><small>LinkedIn</small><strong>Professional profile</strong></span><span class=\"info-arrow\">↗</span></a>\n";
    s += "<div class=\"cv-card\"><div><p class=\"section-kicker\">A little more detail</p><h3>View my CV</h3><p>My education, technical skills and project experience are all in one place.</p></div><a class=\"btn\" href=\"resume.html\">Open CV page <span aria-hidden=\"true\">→</span></a></div>\n";
    s += "</div></section>\n";
    s += footerHtml();
    return s;
}

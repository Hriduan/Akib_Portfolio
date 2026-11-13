// A warm editorial design system for Akib's engineering portfolio.
#pragma once
#include <string>
using namespace std;

const string CSS_TEXT = R"CSS(
:root {
  color-scheme: light;
  --bg: #FAF6F2;
  --paper: #FFFCF9;
  --surface: #F2EBE4;
  --surface-strong: #E9DED3;
  --ink: #20292C;
  --muted: #596366;
  --line: #D8CEC4;
  --accent: #8F3E2D;
  --accent-soft: #F1DED3;
  --green: #4E6759;
  --radius: 10px;
  --body: "Segoe UI", system-ui, -apple-system, sans-serif;
  --head: Georgia, "Times New Roman", serif;
}
* { box-sizing: border-box; }
html { scroll-behavior: smooth; }
body { margin: 0; background: var(--bg); color: var(--ink); font-family: var(--body); font-size: 16px; line-height: 1.62; overflow-x: hidden; }
img { display: block; max-width: 100%; }
a { color: inherit; }
button, input, textarea { font: inherit; }
ul { list-style: none; margin: 0; padding: 0; }
h1, h2, h3, h4, p { margin-top: 0; }
h1, h2, h3 { font-family: var(--head); line-height: 1.12; font-weight: 500; }
.wrap { width: min(1100px, calc(100% - 48px)); margin-inline: auto; }
:focus-visible { outline: 3px solid var(--accent); outline-offset: 4px; }
::selection { background: #E7B8A4; color: var(--ink); }

/* Editorial navigation */
#progress { position: fixed; z-index: 200; inset: 0 auto auto 0; height: 3px; width: 100%; background: var(--accent); transform: scaleX(0); transform-origin: left; }
@supports (animation-timeline: scroll()) { #progress { animation: grow linear; animation-timeline: scroll(root); } }
.nav { position: sticky; top: 0; z-index: 100; background: rgba(250,246,242,.96); border-bottom: 1px solid var(--line); }
.nav-in { height: 72px; display: flex; align-items: center; justify-content: space-between; gap: 28px; }
.logo { display: inline-flex; align-items: center; gap: 11px; color: var(--ink); text-decoration: none; font-weight: 700; letter-spacing: -.02em; font-size: 1.08rem; white-space: nowrap; }
.logo-mark { width: 34px; height: 34px; display: grid; place-items: center; border-radius: 8px 8px 8px 2px; color: var(--bg); background: var(--accent); font-size: .79rem; letter-spacing: .02em; }
.nav nav ul { display: flex; align-items: center; gap: 5px; }
.nav nav a { display: inline-flex; align-items: center; min-height: 42px; padding: 8px 12px; border-radius: 6px; color: var(--muted); text-decoration: none; font-size: .91rem; transition: color .18s ease, background .18s ease; }
.nav nav a:hover, .nav nav a.active { color: var(--ink); background: var(--surface); }
.nav nav a.active { box-shadow: inset 0 -2px 0 var(--accent); }
.menu-check { position: absolute; width: 1px; height: 1px; opacity: 0; overflow: hidden; }
.menu-btn { display: none; width: 46px; height: 46px; border: 1px solid var(--line); border-radius: 8px; background: var(--paper); cursor: pointer; }
.menu-btn span { display: block; width: 19px; height: 2px; margin: 4px auto; background: var(--ink); transition: transform .18s ease, opacity .18s ease; }
.menu-check:focus-visible + .menu-btn { outline: 3px solid var(--accent); outline-offset: 3px; }
.menu-check:checked + .menu-btn span:first-child { transform: translateY(6px) rotate(45deg); }
.menu-check:checked + .menu-btn span:nth-child(2) { opacity: 0; }
.menu-check:checked + .menu-btn span:last-child { transform: translateY(-6px) rotate(-45deg); }

/* Buttons, labels, and page rhythm */
.btn { display: inline-flex; align-items: center; justify-content: center; gap: 10px; min-height: 48px; padding: 11px 18px; border: 1px solid var(--line); border-radius: 6px; background: var(--paper); color: var(--ink); text-decoration: none; font-size: .96rem; font-weight: 650; transition: background .18s ease, border-color .18s ease, transform .18s ease; }
.btn:hover { border-color: var(--accent); transform: translateY(-1px); }
.btn.primary { background: var(--accent); color: #fff; border-color: var(--accent); }
.btn.primary:hover { background: #753322; border-color: #753322; }
.btn-row { display: flex; flex-wrap: wrap; gap: 12px; margin-top: 25px; }
.tag { display: inline-flex; align-items: center; min-height: 30px; padding: 4px 10px; border: 1px solid var(--line); border-radius: 999px; background: var(--paper); color: var(--muted); font-size: .875rem; }
.tags { display: flex; flex-wrap: wrap; gap: 8px; }
.section { padding-block: 70px; }
.section-head { max-width: 680px; margin-bottom: 28px; }
.section-head h2 { margin-bottom: 11px; font-size: clamp(2rem, 4vw, 3.1rem); letter-spacing: -.025em; }
.section-head p { max-width: 62ch; margin-bottom: 0; color: var(--muted); }
.section-kicker, .hero-hi { color: var(--accent); text-transform: uppercase; letter-spacing: .11em; font-size: .875rem; line-height: 1.4; font-weight: 750; }
.section-kicker { margin-bottom: 11px; }
.page-hero { padding: 64px 0 18px; }
.page-hero h1 { max-width: 880px; margin-bottom: 13px; font-size: clamp(2.5rem, 6vw, 4.35rem); letter-spacing: -.035em; }
.page-hero p { max-width: 65ch; margin-bottom: 0; color: var(--muted); font-size: 1.06rem; }
.crumb { display: inline-block; margin-bottom: 22px; color: var(--accent); text-decoration: none; font-size: .95rem; font-weight: 650; }
.crumb:hover { text-decoration: underline; text-underline-offset: 4px; }

/* Home: portrait-led introduction */
.hero { display: grid; grid-template-columns: 1.16fr .84fr; align-items: center; gap: clamp(40px, 8vw, 104px); min-height: 590px; padding-block: 62px 66px; }
.hero-hi { margin-bottom: 19px; }
.hero h1 { max-width: 760px; margin-bottom: 15px; font-size: clamp(3.7rem, 8.8vw, 7rem); letter-spacing: -.065em; line-height: .94; }
.hero-period { color: var(--accent); }
.hero-role { max-width: 600px; margin-bottom: 12px; color: var(--green); font-size: clamp(1.14rem, 2vw, 1.4rem); font-weight: 650; }
.hero-role span { color: var(--muted); font-weight: 450; }
.hero-text { max-width: 54ch; margin-bottom: 0; color: var(--muted); font-size: 1.05rem; }
.photo-wrap { position: relative; width: min(100%, 365px); margin-inline: auto; }
.photo-frame { padding: 9px; background: var(--paper); border: 1px solid var(--line); border-radius: 8px 8px 90px 8px; box-shadow: 15px 15px 0 var(--surface-strong); }
.photo-frame img { width: 100%; aspect-ratio: 4 / 5; object-fit: cover; object-position: center 32%; border-radius: 4px 4px 82px 4px; background: var(--surface); }
.photo-badge { position: absolute; left: -28px; bottom: 22px; max-width: calc(100% + 20px); padding: 10px 14px; background: var(--ink); color: #fff; border-left: 4px solid #D28363; font-size: .875rem; font-weight: 650; }
.hero-meta { display: flex; flex-wrap: wrap; gap: 10px 26px; margin-top: 32px; padding-top: 15px; border-top: 1px solid var(--line); color: var(--muted); font-size: .89rem; }
.hero-meta b { display: block; margin-bottom: 2px; color: var(--ink); font-size: .875rem; text-transform: uppercase; letter-spacing: .08em; }

/* Akib's video feature: a restrained editorial frame distinct from the hero */
.intro-feature { display: grid; grid-template-columns: .72fr 1.28fr; align-items: center; gap: clamp(28px, 5vw, 64px); margin-block: 8px 24px; padding: clamp(24px, 4vw, 46px); border: 1px solid var(--line); border-left: 5px solid var(--accent); border-radius: 4px 14px 14px 4px; background: var(--surface); }
.intro-feature-copy h2 { max-width: 16ch; margin-bottom: 14px; font-size: clamp(1.8rem, 3.4vw, 2.55rem); letter-spacing: -.025em; }
.intro-feature-copy > p:not(.section-kicker) { max-width: 43ch; margin-bottom: 0; color: var(--muted); }
.intro-feature-meta { display: flex; flex-wrap: wrap; gap: 8px 18px; margin-top: 22px; color: var(--green); font-size: .875rem; font-weight: 700; }
.intro-feature-meta span + span { padding-left: 18px; border-left: 1px solid #BEB3A9; }
.intro-feature-player { min-width: 0; padding: 13px; border-radius: 8px; background: var(--ink); }
.intro-player-heading { display: flex; flex-wrap: wrap; justify-content: space-between; gap: 7px 16px; margin: 1px 2px 11px; color: #F3EDE6; font-size: .78rem; font-weight: 700; letter-spacing: .08em; }
.intro-feature-player video { display: block; width: 100%; aspect-ratio: 16 / 9; border-radius: 4px; background: #11191B; object-fit: contain; }
.intro-player-note { margin: 9px 2px 1px; color: #D5D8D4; font-size: .875rem; }

/* Editorial snapshot and interests */
.snapshot { display: grid; grid-template-columns: 1.2fr .8fr; background: var(--surface); border: 1px solid var(--line); border-radius: var(--radius); overflow: hidden; }
.snapshot-copy { padding: clamp(25px, 4.5vw, 48px); }
.snapshot-copy h2 { max-width: 16ch; margin-bottom: 15px; font-size: clamp(1.8rem, 3.5vw, 2.7rem); letter-spacing: -.025em; }
.snapshot-copy > p:not(.section-kicker) { max-width: 56ch; color: var(--muted); }
.text-link { display: inline-flex; align-items: center; gap: 8px; color: var(--accent); text-decoration: none; font-size: .95rem; font-weight: 700; }
.text-link:hover { text-decoration: underline; text-underline-offset: 4px; }
.snapshot-copy .text-link { margin-top: 8px; }
.snapshot-stats { display: grid; align-content: center; border-left: 1px solid var(--line); background: rgba(255,252,249,.58); }
.snapshot-stat { display: flex; align-items: baseline; justify-content: space-between; gap: 14px; padding: 17px 24px; border-bottom: 1px solid var(--line); }
.snapshot-stat:last-child { border-bottom: 0; }
.snapshot-stat b { color: var(--accent); font-family: var(--head); font-size: clamp(1.8rem, 3vw, 2.6rem); font-weight: 500; line-height: 1; }
.snapshot-stat span { max-width: 150px; color: var(--muted); text-align: right; font-size: .88rem; }
.grid { display: grid; grid-template-columns: repeat(auto-fit, minmax(230px, 1fr)); gap: 14px; }
.card { padding: 24px; border: 1px solid var(--line); border-radius: var(--radius); background: var(--paper); }
.interest { min-height: 185px; }
.interest-index { display: block; margin-bottom: 22px; color: var(--accent); font-family: var(--head); font-size: 1rem; }
.interest h3, .card h3 { margin-bottom: 9px; font-size: 1.25rem; }
.interest p, .card p { margin-bottom: 0; color: var(--muted); font-size: .95rem; }
.section-head-row { display: flex; align-items: end; justify-content: space-between; gap: 25px; max-width: none; }
.section-head-row .text-link { flex: none; margin-bottom: 5px; }

/* Project cards: typographic covers, never mock project evidence */
.projects-grid { display: grid; grid-template-columns: repeat(2, minmax(0, 1fr)); gap: 18px; }
.tile { display: flex; flex-direction: column; min-width: 0; overflow: hidden; border: 1px solid var(--line); border-radius: var(--radius); background: var(--paper); color: inherit; text-decoration: none; transition: transform .18s ease, box-shadow .18s ease, border-color .18s ease; }
.tile:hover { transform: translateY(-3px); border-color: #B9A99A; box-shadow: 0 10px 24px rgba(45,36,29,.08); }
.tile-cover { position: relative; display: flex; flex-direction: column; justify-content: space-between; min-height: 245px; padding: 23px; overflow: hidden; background: #E5EDE7; }
.tile:nth-child(even) .tile-cover { background: #F0E1D7; }
.tile-index { color: var(--green); font-size: .875rem; font-weight: 750; letter-spacing: .11em; text-transform: uppercase; }
.tile-cat { display: inline-flex; align-self: flex-start; max-width: 100%; margin-top: 21px; padding: 5px 9px; border: 1px solid rgba(32,41,44,.2); border-radius: 4px; color: var(--ink); background: rgba(255,252,249,.55); font-size: .875rem; }
.tile-cover h3 { max-width: 19ch; margin: 14px 0 0; font-size: clamp(1.55rem, 3vw, 2.2rem); letter-spacing: -.025em; }
.tile-cover-footer { display: flex; justify-content: space-between; gap: 12px; margin-top: 22px; padding-top: 11px; border-top: 1px solid rgba(32,41,44,.18); color: var(--muted); font-size: .875rem; }
.tile-cover-footer b { color: var(--accent); font-size: 1rem; }
.tile-img { position: relative; min-height: 220px; overflow: hidden; background: var(--surface); }
.tile-img img { width: 100%; height: 100%; min-height: 220px; object-fit: cover; }
.tile-img .tile-cat { position: absolute; top: 14px; left: 14px; z-index: 1; margin: 0; }
.tile-body { display: flex; flex: 1; flex-direction: column; gap: 20px; padding: 22px 23px; }
.tile-body p { color: var(--muted); font-size: .96rem; }
.more { display: inline-flex; align-items: center; gap: 8px; color: var(--accent); font-weight: 700; font-size: .9rem; }
.more b { font-size: 1.1rem; }

/* Project details */
.detail { display: grid; grid-template-columns: minmax(0, 1.55fr) minmax(235px, .65fr); gap: 34px; align-items: start; }
.gallery { display: grid; grid-template-columns: repeat(2, minmax(0, 1fr)); gap: 14px; }
.gallery figure { overflow: hidden; margin: 0; border: 1px solid var(--line); border-radius: 8px; background: var(--paper); }
.gallery figure a { display: block; color: inherit; text-decoration: none; }
.gallery img { width: 100%; aspect-ratio: 4 / 3; object-fit: contain; background: var(--surface); }
.gallery figcaption { padding: 11px 13px; color: var(--muted); font-size: .875rem; }
.side-box { position: sticky; top: 95px; }
.side-box h3 { margin: 0 0 10px; font-size: 1rem; }
.side-box .tags { margin-bottom: 24px; }
.text-block { margin-top: 6px; }
.text-block h2 { margin: 0 0 14px; font-size: 1.75rem; }
.text-block h2:not(:first-child) { margin-top: 34px; }
.text-block p { max-width: 72ch; margin: 0 0 14px; color: var(--muted); }
.check { padding: 0; }
.check li { position: relative; margin-bottom: 10px; padding-left: 26px; }
.check li::before { position: absolute; left: 1px; top: .16em; color: var(--accent); content: "—"; font-weight: 700; }
.pager { display: flex; gap: 12px; margin-top: 34px; }
.pager a { flex: 1; min-width: 0; padding: 16px; border: 1px solid var(--line); border-radius: 8px; background: var(--paper); text-decoration: none; }
.pager a:hover { border-color: var(--accent); }
.pager small { display: block; margin-bottom: 5px; color: var(--muted); font-size: .875rem; }
.pager a.next { text-align: right; }
.lightbox { position: fixed; inset: 0; z-index: 500; display: none; place-items: center; padding: 24px; background: rgba(24,29,30,.94); color: #fff; text-align: center; text-decoration: none; }
.lightbox:target { display: grid; }
.lightbox img { max-width: min(90vw, 1050px); max-height: 80vh; margin: 0 auto; border-radius: 8px; background: #fff; }
.lightbox p { margin: 12px 0 0; color: #fff; }

/* About and experience */
.about { display: grid; grid-template-columns: .65fr 1.35fr; align-items: center; gap: clamp(38px, 7vw, 86px); }
.about-photo { max-width: 300px; }
.photo-caption { margin: 18px 0 0; color: var(--muted); font-size: .9rem; }
.about-copy > p:not(.section-kicker) { max-width: 67ch; margin-bottom: 16px; color: var(--muted); }
.about-copy .tags { margin-top: 23px; }
.timeline { margin-left: 9px; padding-left: 27px; border-left: 1px solid var(--line); }
.t-item { position: relative; margin-bottom: 13px; padding: 22px 24px; }
.t-item::before { position: absolute; left: -34px; top: 29px; width: 12px; height: 12px; border: 3px solid var(--bg); border-radius: 50%; background: var(--accent); box-shadow: 0 0 0 1px var(--accent); content: ""; }
.t-item small { display: block; margin-bottom: 10px; color: var(--accent); font-size: .875rem; font-weight: 700; }
.t-item p + p { margin-top: 5px; }
.t-item .tag { margin-top: 11px; }
.coursework { margin-top: 14px !important; font-size: .91rem !important; }
.skill-card h3 { margin-bottom: 16px; color: var(--accent); }
.experience-layout > .section-head { margin-bottom: 26px; }

/* Resume and contact */
.resume-layout { display: grid; grid-template-columns: .72fr 1.28fr; gap: 18px; align-items: stretch; }
.resume-copy { display: flex; flex-direction: column; justify-content: center; padding: clamp(24px, 4vw, 42px); background: var(--surface); }
.resume-copy h2 { margin: 8px 0 13px; font-size: clamp(2rem, 4vw, 3rem); }
.resume-copy p:not(.resume-kicker) { color: var(--muted); }
.resume-kicker { color: var(--accent); font-size: .875rem; font-weight: 700; }
.resume-viewer { padding: 8px; }
.resume-preview-link { display: block; border: 1px solid var(--line); border-radius: 5px; overflow: hidden; background: #fff; }
.resume-preview { width: 100%; height: auto; }
.resume-fallback { margin: 11px 6px 5px; color: var(--muted); font-size: .88rem; }
.resume-fallback a { color: var(--accent); }
.contact-section { display: grid; grid-template-columns: .82fr 1.18fr; gap: clamp(28px, 6vw, 74px); align-items: start; }
.contact-intro h2 { max-width: 11ch; margin-bottom: 13px; font-size: clamp(2.4rem, 5vw, 4rem); }
.contact-intro > p:not(.section-kicker) { max-width: 40ch; margin-bottom: 22px; color: var(--muted); }
.info-link { display: flex; align-items: center; gap: 14px; min-height: 74px; margin-bottom: 9px; padding: 12px 15px; border: 1px solid var(--line); border-radius: 8px; background: var(--paper); text-decoration: none; }
.info-link:hover { border-color: var(--accent); }
.info-link small { display: block; margin-bottom: 2px; color: var(--muted); font-size: .875rem; }
.info-link strong { display: block; overflow-wrap: anywhere; font-weight: 650; }
.ico { flex: 0 0 40px; display: grid; place-items: center; width: 40px; height: 40px; border-radius: 7px; background: var(--accent-soft); color: var(--accent); font-size: .875rem; font-weight: 750; }
.info-arrow { margin-left: auto; color: var(--accent); }
.cv-card { display: flex; align-items: center; justify-content: space-between; gap: 18px; margin-top: 17px; padding: 21px; border: 1px solid var(--line); border-radius: 8px; background: var(--surface); }
.cv-card h3 { margin-bottom: 5px; font-size: 1.35rem; }
.cv-card p:not(.section-kicker) { color: var(--muted); font-size: .9rem; }
.cv-card .section-kicker { margin-bottom: 6px; }

/* Closing callout and compact universal footer */
.cta { width: min(1100px, calc(100% - 48px)); margin: 34px auto 0; padding: clamp(26px, 4vw, 42px); border: 1px solid var(--line); border-radius: var(--radius); background: var(--surface); }
.cta h2 { max-width: 25ch; margin: 0 auto 9px; font-size: clamp(1.8rem, 3.5vw, 2.7rem); text-align: center; }
.cta p { max-width: 58ch; margin: 0 auto; color: var(--muted); text-align: center; }
.cta .btn-row { justify-content: center; margin-top: 18px; }
.footer { margin-top: 34px; border-top: 1px solid var(--line); background: #F3ECE5; }
.footer-inner { padding-block: 12px 9px; }
.footer-primary { display: flex; min-height: 43px; align-items: center; justify-content: space-between; gap: 18px; }
.footer-logo { font-size: .94rem; }
.footer-logo .logo-mark { width: 28px; height: 28px; font-size: .7rem; }
.footer-nav ul { display: flex; flex-wrap: wrap; justify-content: center; gap: 2px 9px; }
.footer-nav a, .footer-actions a { display: inline-flex; align-items: center; min-height: 34px; padding: 4px 5px; color: var(--muted); text-decoration: none; font-size: .875rem; }
.footer-nav a:hover, .footer-actions a:hover { color: var(--accent); text-decoration: underline; text-underline-offset: 3px; }
.footer-actions { display: flex; align-items: center; gap: 8px; }
.footer-actions a:last-child { color: var(--accent); font-weight: 700; }
.footer-bottom { display: flex; align-items: center; justify-content: space-between; gap: 12px; min-height: 28px; padding-top: 6px; border-top: 1px solid rgba(32,41,44,.12); color: var(--muted); font-size: .875rem; }
.to-top { color: var(--muted); text-decoration: none; }
.to-top:hover { color: var(--accent); }

/* Small screens, visible keyboard focus, and reduced motion */
@keyframes grow { to { transform: scaleX(1); } }
@media (max-width: 900px) {
  .hero { min-height: 0; gap: 46px; padding-block: 52px 58px; }
  .hero h1 { font-size: clamp(3.5rem, 9vw, 5.5rem); }
  .detail { grid-template-columns: minmax(0, 1fr) 250px; gap: 22px; }
  .resume-layout { grid-template-columns: 1fr; }
  .resume-copy { min-height: 250px; }
  .footer-primary { flex-wrap: wrap; }
}
@media (max-width: 760px) {
  .wrap { width: min(100% - 36px, 640px); }
  .nav-in { height: 66px; }
  .menu-btn { display: block; }
  .nav nav { position: absolute; top: 66px; left: 0; right: 0; max-height: 0; overflow: hidden; visibility: hidden; border-bottom: 0 solid var(--line); background: var(--bg); transition: max-height .22s ease, border-width .22s ease, visibility .22s ease; }
  #menuToggle:checked + .menu-btn + #menu { max-height: 400px; visibility: visible; border-bottom-width: 1px; }
  .nav nav ul { display: grid; grid-template-columns: repeat(2, minmax(0, 1fr)); gap: 4px; padding: 12px 18px 17px; }
  .nav nav a { min-height: 44px; padding-inline: 12px; }
  .hero { grid-template-columns: 1fr .75fr; gap: 30px; padding-block: 48px 45px; }
  .hero h1 { font-size: clamp(3.1rem, 9vw, 4.8rem); }
  .intro-feature { grid-template-columns: 1fr; gap: 22px; }
  .photo-badge { left: -13px; bottom: 15px; }
  .snapshot { grid-template-columns: 1fr; }
  .snapshot-stats { grid-template-columns: repeat(3, 1fr); border-top: 1px solid var(--line); border-left: 0; }
  .snapshot-stat { display: block; padding: 16px 12px; border-right: 1px solid var(--line); border-bottom: 0; }
  .snapshot-stat:last-child { border-right: 0; }
  .snapshot-stat span { display: block; max-width: none; margin-top: 6px; text-align: left; }
  .detail { grid-template-columns: 1fr; }
  .side-box { position: static; }
  .contact-section { grid-template-columns: 1fr; }
  .contact-intro h2 { max-width: 18ch; }
  .footer-primary { justify-content: space-between; }
  .footer-nav { order: 3; flex: 1 0 100%; }
  .footer-nav ul { justify-content: flex-start; }
}
@media (max-width: 560px) {
  body { font-size: 16px; }
  .wrap { width: calc(100% - 32px); }
  .section { padding-block: 49px; }
  .page-hero { padding-top: 45px; }
  .hero { grid-template-columns: 1fr; gap: 34px; padding-top: 36px; }
  .hero-copy { order: 2; }
  .photo-wrap { order: 1; width: min(74%, 270px); }
  .photo-badge { left: -18px; bottom: 12px; }
  .hero h1 { font-size: clamp(3.3rem, 13vw, 4.9rem); }
  .hero-meta { gap: 12px 22px; }
  .snapshot-copy { padding: 23px; }
  .snapshot-stats { grid-template-columns: 1fr; }
  .snapshot-stat { display: flex; align-items: baseline; justify-content: space-between; padding: 13px 20px; border-right: 0; border-bottom: 1px solid var(--line); }
  .snapshot-stat:last-child { border-bottom: 0; }
  .snapshot-stat span { margin-top: 0; text-align: right; }
  .grid, .projects-grid { grid-template-columns: 1fr; }
  .interest { min-height: 0; }
  .section-head-row { align-items: flex-start; flex-direction: column; }
  .tile-cover { min-height: 220px; }
  .about { grid-template-columns: 1fr; gap: 33px; }
  .about-photo { width: min(72%, 260px); }
  .timeline { margin-left: 5px; padding-left: 21px; }
  .t-item::before { left: -28px; }
  .t-item { padding: 20px; }
  .gallery { grid-template-columns: 1fr; }
  .pager { flex-direction: column; }
  .pager a.next { text-align: left; }
  .resume-preview { width: 100%; height: auto; }
  .cv-card { align-items: flex-start; flex-direction: column; }
  .cta { width: calc(100% - 32px); }
  .footer-inner { padding-block: 11px 8px; }
  .footer-primary { align-items: flex-start; gap: 5px 10px; }
  .footer-nav ul { gap: 0 7px; }
  .footer-bottom { flex-wrap: wrap; justify-content: flex-start; font-size: .875rem; }
  .footer-bottom > span:nth-child(2) { margin-left: auto; }
}
@media (prefers-reduced-motion: reduce) {
  *, *::before, *::after { scroll-behavior: auto !important; animation-duration: .01ms !important; animation-iteration-count: 1 !important; transition-duration: .01ms !important; }
}
)CSS";


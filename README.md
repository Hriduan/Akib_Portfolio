# Akib Rahman — Engineering Portfolio

A warm, responsive e-portfolio for Akib Rahman, a final-year Electrical and Electronic Engineering student at AIUB. The site uses a small C++17 generator and static HTML/CSS so it can run without a JavaScript framework.

## Pages

- `index.html` — introduction, interests and selected work
- `about.html` — profile and education
- `projects.html` — two CV-grounded project summaries
- `experience.html` — collaboration and technical skills
- `resume.html` — downloadable and embedded CV
- `contact.html` — email, phone and location
- `project-*.html` — detailed project notes

## Build and preview

From this folder:

```bash
g++ -std=c++17 main.cpp -o build_site
./build_site
python3 tools/check_site.py
```

Then open `index.html` in a browser. The source of truth is `about-me.txt`, the project text files under `projects/`, and the shared layout/style files under `ui/`. Rebuild after changing content.

## Assets

- `assets/akib-rahman.jpg` — supplied profile portrait
- `assets/Akib_Rahman_CV.pdf` — portfolio-ready CV based on the supplied information

Project pages do not use invented prototype photos or performance measurements. Add authentic images only when Akib can verify and share them.

## Deploy

The included GitHub Actions workflow builds and checks the static site on pushes to `main`. Configure GitHub Pages for the repository before publishing. The site has not been deployed by this package.

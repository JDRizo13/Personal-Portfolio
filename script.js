document.addEventListener('DOMContentLoaded', () => {
  // Year stamp
  const yearSpan = document.getElementById('year');
  if (yearSpan) yearSpan.textContent = new Date().getFullYear();

  // Theme init
  const savedTheme = localStorage.getItem('theme');
  const prefersDark = window.matchMedia('(prefers-color-scheme: dark)').matches;
  const isDark = savedTheme === 'dark' || (savedTheme === null && prefersDark);
  if (isDark) document.documentElement.classList.add('dark');
  updateThemeIcons(isDark);

  // Theme toggle
  const themeBtn = document.getElementById('theme-toggle');
  themeBtn?.addEventListener('click', () => {
    const dark = document.documentElement.classList.toggle('dark');
    themeBtn.setAttribute('aria-pressed', String(dark));
    localStorage.setItem('theme', dark ? 'dark' : 'light');
    updateThemeIcons(dark);
  });

  function updateThemeIcons(dark) {
    const sun = document.getElementById('icon-sun');
    const moon = document.getElementById('icon-moon');
    if (sun) sun.style.display = dark ? 'none' : '';
    if (moon) moon.style.display = dark ? '' : 'none';
  }

  // Show resume nav button on scroll
  const resumeNavBtn = document.getElementById('resume-nav-btn');
  if (resumeNavBtn) {
    resumeNavBtn.style.display = '';
    resumeNavBtn.style.opacity = '0';
    resumeNavBtn.style.transition = 'opacity .3s';
    window.addEventListener('scroll', () => {
      resumeNavBtn.style.opacity = window.scrollY > 200 ? '1' : '0';
    }, { passive: true });
  }

  // Close mobile menu after navigation
  document.querySelectorAll('.mobile-panel a').forEach(a => {
    a.addEventListener('click', () => {
      const toggle = document.getElementById('menu-toggle');
      if (toggle) toggle.checked = false;
    });
  });

  // Contact form → Formspree
  const form = document.getElementById('contact-form');
  const status = document.getElementById('form-status');
  const FORMSPREE_ENDPOINT = 'https://formspree.io/f/mpwlboyr';

  if (form && status) {
    form.addEventListener('submit', async (e) => {
      e.preventDefault();
      const submitBtn = form.querySelector('[type="submit"]');
      if (submitBtn) submitBtn.disabled = true;
      status.textContent = 'Sending…';

      try {
        const r = await fetch(FORMSPREE_ENDPOINT, {
          method: 'POST',
          headers: { Accept: 'application/json' },
          body: new FormData(form),
        });
        if (r.ok) {
          form.reset();
          status.textContent = '✓ Thanks! Your message was sent.';
        } else {
          const res = await r.json().catch(() => ({}));
          status.textContent = res.errors?.map(e => e.message).join(' ')
            || 'There was an issue sending your message. Please try again.';
        }
      } catch {
        status.textContent = 'Network error. Please try again later.';
      } finally {
        if (submitBtn) submitBtn.disabled = false;
      }
    });
  }

  // Scroll fade-in animations
  const observer = new IntersectionObserver(
    entries => entries.forEach(entry => {
      if (entry.isIntersecting) {
        entry.target.classList.add('visible');
        observer.unobserve(entry.target);
      }
    }),
    { threshold: 0.08 }
  );
  document.querySelectorAll('.fade-up').forEach(el => observer.observe(el));

  // BMR / TDEE calculator (demo page)
  const bmrForm = document.getElementById('bmr-form');
  const bmrOut = document.getElementById('bmr-output');
  if (bmrForm && bmrOut) {
    function fmt(n) { return Number(n).toLocaleString(undefined, { maximumFractionDigits: 0 }); }

    bmrForm.addEventListener('submit', e => {
      e.preventDefault();
      const data = new FormData(bmrForm);
      const sex = data.get('sex');
      const age = Number(data.get('age'));
      const height = Number(data.get('height'));
      const weight = Number(data.get('weight'));
      const activity = Number(data.get('activity'));
      if (!sex || !age || !height || !weight || !activity) {
        bmrOut.textContent = 'Please fill out all fields.';
        return;
      }
      const s = sex === 'male' ? 5 : -161;
      const bmr = (10 * weight) + (6.25 * height) - (5 * age) + s;
      const tdee = bmr * activity;
      bmrOut.innerHTML = `
        <div class="result-grid">
          <div><strong>BMR</strong><div class="num">${fmt(bmr)} kcal/day</div></div>
          <div><strong>TDEE</strong><div class="num">${fmt(tdee)} kcal/day</div></div>
        </div>
        <p class="muted">BMR uses the Mifflin–St Jeor equation; TDEE multiplies by your selected activity level.</p>
      `;
    });
    bmrForm.addEventListener('reset', () => { bmrOut.textContent = ''; });
  }
});

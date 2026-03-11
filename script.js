// Year stamp
document.addEventListener('DOMContentLoaded', () => {
  // Restore saved theme
  const savedTheme = localStorage.getItem('theme');
  if (savedTheme === 'dark' || (savedTheme === null && window.matchMedia && window.matchMedia('(prefers-color-scheme: dark)').matches)) {
    document.documentElement.classList.add('dark');
    document.documentElement.style.colorScheme = 'dark';
  }
  const yearSpan = document.getElementById('year');
  if (yearSpan) yearSpan.textContent = new Date().getFullYear();

  // Theme toggle (respects system by default; this simply flips a class)
  const btn = document.getElementById('theme-toggle');
  btn?.addEventListener('click', () => {
    const dark = document.documentElement.classList.toggle('dark');
    document.documentElement.style.colorScheme = dark ? 'dark' : 'light';
    btn.setAttribute('aria-pressed', String(dark));
    localStorage.setItem('theme', dark ? 'dark' : 'light');
  
  // Contact form -> Formspree
  const form = document.getElementById('contact-form');
  const status = document.getElementById('form-status');
  const FORMSPREE_ENDPOINT = 'https://formspree.io/f/mpwlboyr'; // <- replace with your Formspree ID

  if (form && status) {
    form.addEventListener('submit', async (e) => {
      e.preventDefault();

      status.textContent = 'Sending...';
      const data = new FormData(form);

      try {
        const r = await fetch(FORMSPREE_ENDPOINT, {
          method: 'POST',
          headers: { 'Accept': 'application/json' },
          body: data
        });

        if (r.ok) {
          form.reset();
          status.textContent = 'Thanks! Your message was sent.';
        } else {
          const res = await r.json().catch(() => ({}));
          if (res && res.errors && res.errors.length) {
            status.textContent = res.errors.map(e => e.message).join(' ');
          } else {
            status.textContent = 'There was an issue sending your message. Please try again.';
          }
        }
      } catch (err) {
        status.textContent = 'Network error. Please try again later.';
      }
    });
  }

});

  // Close mobile menu after navigating
  document.querySelectorAll('.mobile-panel a').forEach(a => {
    a.addEventListener('click', () => {
      const toggle = document.getElementById('menu-toggle');
      if (toggle) toggle.checked = false;
    
  // Contact form -> Formspree
  const form = document.getElementById('contact-form');
  const status = document.getElementById('form-status');
  const FORMSPREE_ENDPOINT = 'https://formspree.io/f/mpwlboyr'; // <- replace with your Formspree ID

  if (form && status) {
    form.addEventListener('submit', async (e) => {
      e.preventDefault();

      status.textContent = 'Sending...';
      const data = new FormData(form);

      try {
        const r = await fetch(FORMSPREE_ENDPOINT, {
          method: 'POST',
          headers: { 'Accept': 'application/json' },
          body: data
        });

        if (r.ok) {
          form.reset();
          status.textContent = 'Thanks! Your message was sent.';
        } else {
          const res = await r.json().catch(() => ({}));
          if (res && res.errors && res.errors.length) {
            status.textContent = res.errors.map(e => e.message).join(' ');
          } else {
            status.textContent = 'There was an issue sending your message. Please try again.';
          }
        }
      } catch (err) {
        status.textContent = 'Network error. Please try again later.';
      }
    });
  }

});
  
  // Contact form -> Formspree
  const form = document.getElementById('contact-form');
  const status = document.getElementById('form-status');
  const FORMSPREE_ENDPOINT = 'https://formspree.io/f/mpwlboyre'; // <- replace with your Formspree ID

  if (form && status) {
    form.addEventListener('submit', async (e) => {
      e.preventDefault();

      status.textContent = 'Sending...';
      const data = new FormData(form);

      try {
        const r = await fetch(FORMSPREE_ENDPOINT, {
          method: 'POST',
          headers: { 'Accept': 'application/json' },
          body: data
        });

        if (r.ok) {
          form.reset();
          status.textContent = 'Thanks! Your message was sent.';
        } else {
          const res = await r.json().catch(() => ({}));
          if (res && res.errors && res.errors.length) {
            status.textContent = res.errors.map(e => e.message).join(' ');
          } else {
            status.textContent = 'There was an issue sending your message. Please try again.';
          }
        }
      } catch (err) {
        status.textContent = 'Network error. Please try again later.';
      }
    });
  }

});

  // Contact form -> Formspree
  const form = document.getElementById('contact-form');
  const status = document.getElementById('form-status');
  const FORMSPREE_ENDPOINT = 'https://formspree.io/f/mpwlboyr'; // <- replace with your Formspree ID

  if (form && status) {
    form.addEventListener('submit', async (e) => {
      e.preventDefault();

      status.textContent = 'Sending...';
      const data = new FormData(form);

      try {
        const r = await fetch(FORMSPREE_ENDPOINT, {
          method: 'POST',
          headers: { 'Accept': 'application/json' },
          body: data
        });

        if (r.ok) {
          form.reset();
          status.textContent = 'Thanks! Your message was sent.';
        } else {
          const res = await r.json().catch(() => ({}));
          if (res && res.errors && res.errors.length) {
            status.textContent = res.errors.map(e => e.message).join(' ');
          } else {
            status.textContent = 'There was an issue sending your message. Please try again.';
          }
        }
      } catch (err) {
        status.textContent = 'Network error. Please try again later.';
      }
    });
  }

  // ====== BMR & TDEE Calculator ======
(function () {
  const form = document.getElementById('bmr-form');
  const out = document.getElementById('bmr-output');
  if (!form || !out) return;

  function fmt(n) { return Number(n).toLocaleString(undefined, { maximumFractionDigits: 0 }); }

  form.addEventListener('submit', (e) => {
    e.preventDefault();
    const data = new FormData(form);
    const sex = data.get('sex');
    const age = Number(data.get('age'));
    const height = Number(data.get('height'));   // cm
    const weight = Number(data.get('weight'));   // kg
    const activity = Number(data.get('activity'));

    if (!sex || !age || !height || !weight || !activity) {
      out.textContent = 'Please fill out all fields.';
      return;
    }

    // Mifflin–St Jeor
    const s = sex === 'male' ? 5 : -161;
    const bmr = (10 * weight) + (6.25 * height) - (5 * age) + s;
    const tdee = bmr * activity;

    out.innerHTML = `
      <div class="result-grid">
        <div><strong>BMR</strong><div class="num">${fmt(bmr)} kcal/day</div></div>
        <div><strong>TDEE</strong><div class="num">${fmt(tdee)} kcal/day</div></div>
      </div>
      <p class="muted">BMR uses the Mifflin–St Jeor equation; TDEE multiplies by your selected activity level.</p>
    `;
  });

  form.addEventListener('reset', () => { out.textContent = ''; });
})();

});
import React from "react";
import './Navbar.css'

export const Navbar = () => {

  const menuBtn = document.querySelector('.menu-open');
      const closeBtn = document.querySelector('.menu-close');
      const nav = document.querySelector('nav ul');

      menuBtn.addEventListener('click', function () {
        nav.classList.add('open');
      });

      closeBtn.addEventListener('click', function () {
        nav.classList.remove('open');
      });

  return (
    <>
    <div className="wrap">
      <header>
        <div className="header-left">
          <a href="index.html"><img src="/logo.svg" alt="Friskay logo" /></a>
          <div className="divider hide-in-mobile"></div>
          <a href="#" className="home hide-in-mobile">Home</a>
        </div>
        <nav>
          <a href="#" className="menu-open">
            <img src="/menu.svg" alt="open menu" />
          </a>
          <ul>
            <li>
              <a href="#" className="menu-close">
                <img src="/close.svg" alt="close menu" />
              </a>
            </li>
            <li><a href="#">Our food</a></li>
            <li><a href="#">Ingredients</a></li>
            <li><a href="#">Studies</a></li>
            <li><a href="#">FAQ</a></li>
          </ul>
        </nav>
      </header>
      </div>
    </>
  )
}

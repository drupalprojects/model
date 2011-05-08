Introduction
------------
The Model Entities module provides a fully working but generic example
about what is good practice in creating and administering entities and integrating
entities with the rest of Drupal Core and the Drupal ecosystem.

It is also a way to quickstart your entities development as the code can directly
be used in your own project.

As mentioned above the code offers no specific domain specific functionality -
it remains generic so as to not to distract away from the main issue and allow
you to literally copy and paste the project. 

This module does not provide any functionality to non-developers.

Installation
-------------
Once you activate the module it sets up an entity administration interface under
Admnistration > Structure > Model Types

You can add model entities via

Administration > Content > Models

Keep in mind that you need to create some Model Types before you can add entities.


Using the code in your projects
-------------------------------
The way I envision using the module in my own projects is, for the time being,
searching and replacing the word "model" with the actual name I want to give my
entity and the base entity table and then adding the domain specific functionality.

It would be nice if this could eventually develop in something that is automated
so via a drush script we can get all the code ready to go.
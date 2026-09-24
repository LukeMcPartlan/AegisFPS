# AEGIS

A modular Unreal Engine 5 multiplayer FPS. Overwatch-style ability gameplay with
fully customizable **characters** (not heroes): a WoW-style character creation
menu, CoD-style loadouts, and **zero hitscan** — every weapon fires replicated
physics projectiles.

> **Working title.** "AEGIS" is a codename. Renaming the project now is cheap;
> say the word before we accumulate content.

## Current state: Phase 0 — scaffold

Compilable UE 5.8 project skeleton. No maps, no art, no abilities yet — just the
modular architecture, the replicated core classes, and the data-driven content
model. The first compile happens on your PC (see Setup).

## Setup (your PC)

Prerequisites:

- Unreal Engine **5.8** (Epic Games Launcher)
- Visual Studio 2022 with the "Game development with C++" workload
- .NET 8 SDK

Steps:

1. `git clone https://github.com/LukeMcPartlan/AegisFPS.git`
2. Right-click `AegisFPS.uproject` → **Generate Visual Studio project files**
3. Open `AegisFPS.sln`, build the **Development Editor** configuration
4. Launch the editor from Visual Studio (or double-click the `.uproject`)
5. First editor launch compiles all game + plugin modules

To test the listen-server path later: Play → Advanced Settings → Net Mode
**Play As Listen Server**, Number of Players **4**.

## Architecture

Thin C++ core, fat data. Content (characters, abilities, weapons, loadouts) is
authored as **DataAssets** — adding content never touches core code.

```
Source/AegisFPS/            Core game module (thin)
  Public/Core/
    AegisGameMode           2v2 now (PlayersPerTeam=2), 6v6 later
    AegisGameState          Replicated team scores
    AegisPlayerState        Replicated TeamId + ActiveLoadout
    AegisPlayerController   Menu flow owner (phase 3)
    AegisCharacter          Replicated character + GAS component + Enhanced Input

Plugins/                    Feature plugins — each is independently editable,
                            replaceable, or removable
  AegisCharacters/          UAegisCharacterDefinition (appearance options,
                            base mesh, stats) — creation-menu data
  AegisAbilities/           UAegisAbilityDefinition (UGameplayAbility class,
                            slot E/Shift, cooldown, icon)
  AegisWeapons/             UAegisWeaponDefinition (slot, projectile class,
                            damage, fire rate, spread, magazine) +
                            AAegisProjectile (server-authoritative,
                            replicated movement, no hitscan)
  AegisLoadouts/            UAegisLoadoutDefinition — 1 character + 2 abilities
                            + (Main+Offhand XOR TwoHanded) + Secondary,
                            with IsValidLoadout() enforcing the rule
  AegisUI/                  Character-creation + loadout menus (phase 3)
```

Key design decisions:

- **Abilities: Gameplay Ability System (GAS).** Built-in plugin, data-driven,
  replication-aware. E and Shift map to the two loadout ability slots.
- **Weapons: projectile-only.** `AAegisProjectile` is the base for all fire.
  Server-authoritative with replicated movement; client-side prediction is a
  deliberate later milestone, not phase 1.
- **Networking now: listen server, 2v2.** `PlayersPerTeam` is a config value;
  the dedicated-server + 6v6 migration is a planned phase, not a rewrite.
- **Input: Enhanced Input.** No legacy bindings; actions are data assets bound
  in `AAegisCharacter::SetupPlayerInputComponent`.

## Roadmap

- [x] **Phase 0** — Repo + modular scaffold (this commit)
- [ ] **Phase 1** — Character movement feel, weapon actor (reads
      `UAegisWeaponDefinition`, spawns projectiles), projectile test range map
- [ ] **Phase 2** — GAS wiring: attribute set (health), ability granting from
      loadout, E/Shift activation, damage via GameplayEffects
- [ ] **Phase 3** — WoW-style character creation menu + CoD-style loadout menu
      (UMG, data-asset driven)
- [ ] **Phase 4** — 2v2 listen-server game loop: teams, rounds, scoring, respawn
- [ ] **Phase 5** — Dedicated server + 6v6, projectile prediction, hardening

## Repo layout

```
AegisFPS.uproject
Config/               Engine/game/input ini files
Source/               AegisFPS game module + .Target.cs files
Plugins/              AegisCharacters, AegisAbilities, AegisWeapons,
                      AegisLoadouts, AegisUI
```

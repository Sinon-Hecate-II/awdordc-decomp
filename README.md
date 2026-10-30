# Advance Wars: Days of Ruin / Dark Conflict — Decompilation

[![Progress](https://bytematch.dev/Sinon-Hecate-II/awdordc-decomp.svg)](https://bytematch.dev/Sinon-Hecate-II/awdordc-decomp)

A work-in-progress decompilation of **Advance Wars: Days of Ruin** (also known as **Advance Wars: Dark Conflict**) for the Nintendo DS.

This project aims to reconstruct the game's code in readable C, understand its internal systems, and work towards matching the original compiled binaries as closely as possible. **It is not a completed, standalone game or a ROM download.**

The following decomplication is majority AI assisted (whatever you want to call it), i'll done a write up further down below to explain stuff  

> [!IMPORTANT]
> This repository is a work in progress. Source files may be automatically generated, incomplete, poorly named, or not yet matching. Build and ROM verification results depend on the supplied original game version and the required toolchain.

## Progress

Decompilation progress is tracked on [ByteMatch](https://bytematch.dev/Sinon-Hecate-II/awdordc-decomp). The badge above links to the live project status.

A source file existing in the repository **does not** mean it is fully understood, byte-matching, or ready to be linked into a verified ROM.

## Repository layout

```text
awdordc-decomp/
├── include/                  # Shared types, structs, and declarations
│   ├── common.h
│   ├── coordinate_bits.h
│   ├── ov000_unit_entry.h
│   └── panel.h
├── src/
│   └── auto/                 # Address-based C decompilation source files
├── tools/
│   ├── configure.py          # Generate build.ninja
│   ├── bytematch_objdiff.py  # Add source metadata for ByteMatch
│   ├── same.py               # Compare built output against the original
│   ├── transform_dep.py      # Transform compiler dependency files
│   └── ninja_syntax.py       # Ninja file generation helper
└── README.md
```

Some directories and generated files referenced by the build scripts (such as `config/`, `extract/`, `build/`, `build.ninja`, and `objdiff.json`) may need to be generated or provided separately; they are not all committed to the repository.

## Building

### Requirements

The checked-in build configuration expects:

- **Python 3** to run the project scripts.
- **Ninja** to execute generated build rules.
- **[ds-decomp](https://github.com/AetiasHax/ds-decomp)** (`dsd`) to extract and delink Nintendo DS code, generate comparison data, and rebuild the ROM.
- **CodeWarrior for Nintendo DS**, with the required `mwccarm.exe` and `mwldarm.exe` executables. The default compiler selected by `tools/configure.py` is `2.0/sp1p5`; individual sources may use versions specified in `file_compilers.json`.
- **Wibo**, optionally, to run the Windows compiler binaries on Linux or macOS.
- A legally obtained copy of the **matching original Nintendo DS ROM**, for local verification.
- The matching `config/<version>/arm9/config.yaml` and related decompilation configuration files.

**Note:** The current repository does not include a committed `config/` directory, so the build instructions below cannot be run successfully from a fresh clone without the corresponding configuration. Do not assume that the version identifier can be guessed from the game's regional title.

### Configure

Clone the repository:

```bash
git clone https://github.com/Sinon-Hecate-II/awdordc-decomp.git
cd awdordc-decomp
```

Place your matching original ROM at `extract/baserom.nds` and provide the corresponding version configuration under `config/<version>/arm9/`.

Generate the Ninja build file:

```bash
python tools/configure.py <version> --dsd /path/to/dsd --compilers /path/to/codewarrior
```

On Linux or macOS, pass a path to Wibo when needed:

```bash
python tools/configure.py <version> --dsd /path/to/dsd --compilers /path/to/codewarrior --wibo /path/to/wibo
```

Replace `<version>` with the actual directory name beneath `config/`. The paths are examples, not included tools.

### Build targets

Once configuration is available and `build.ninja` has been generated:

| Command | Purpose |
| --- | --- |
| `ninja` | Run the default compilation, comparison-data generation, and ROM verification workflow. |
| `ninja prepare` | Prepare decompilation inputs, comparisons, and source objects. |
| `ninja rom` | Rebuild and compare the ROM against the supplied original. |
| `ninja -k 0 all_source` | Attempt to compile all source files, continuing after errors. |

Successful ROM verification requires a matching original and compatible compiler/linker configuration. These commands describe what the build script defines; they are **not** a claim that the current checkout builds successfully.

## Working on the decompilation

Source files under `src/auto/` are predominantly separated by memory address. Names such as `main_02000000.c`, `itcm_01FF8000.c`, and `ov000_02169020.c` identify the original memory region and starting address rather than a fully reverse-engineered subsystem.

When improving code:

1. Pick a function or source unit and inspect its original object and disassembly using the available decompilation tools.
2. Replace unclear generated code with readable, behaviorally equivalent C, preserving known addresses and interfaces where relevant.
3. Compile with the configured CodeWarrior version and flags.
4. Compare generated objects to the original with the generated `objdiff.json` and your preferred compatible diff tooling.
5. Check the effect of the change on matching and builds before considering it complete.

Matching the original binary can depend on seemingly minor details such as types, compiler versions, optimization flags, expression order, and structure layouts.

## Contributing

Contributions that improve readability, document game structures, identify functions, or advance matching are welcome.

Please keep changes focused, explain what was identified or fixed, and include any relevant object comparisons or build results. Avoid committing copyrighted ROMs, extracted commercial assets, proprietary compiler binaries, or generated build output.

You can open an [issue](https://github.com/Sinon-Hecate-II/awdordc-decomp/issues) to discuss findings or propose a change.

## AI / Vibing Coding 

Nearly 90-95% of this Decomp was done by AI, i'm not inherently proud of that as i'm usually the type of guy who is pretty against AI But i knew when i saw with all these decomps going out people were just gonna use it to flex saying "They did this" when in reality its just AI i'm not gonna claim i did this as its nearly all AI i'm not gonna go into a whole rant on decomps and AI here seems pointless in Github readme but i'll list down below the models that were used in this decomp and how many tokens were used 

All of the AI models have been free* I haven't spent a single bit of money on this decomp, all of ChatGPT/Codex were through a free trial they had on Plus sub and the team were constantly doing resets every day which has allowed me to progress way quicker this must likely would have taken another month or two using this method considering the weekly resets. All the other models were through some sort of free API or Limited API but tldr i haven't spend a single bit of money

I'll post the token count from ChatGPT mainly once everything has finished

Gemini 3.8 Flash 
Gemini 3.5 Flash Lite
ChatGPT Codex (GPT-6.1 Sol)
ChatGPT 6 Asta
ChatGPT 6
Deepseek 4.1 Flash
Deepseek 4 Flash 0731-1
Qwen 3.8 27B
Nemotron 3 Ultra 550b
Beam 1.0
Decomp Autopilot

## Legal notice

This is an **unofficial fan reverse-engineering project**. It is not affiliated with, endorsed by, or supported by Nintendo, Intelligent Systems, or any other rights holder.

**Advance Wars**, **Days of Ruin**, and **Dark Conflict**, together with the original game's code, artwork, music, and other assets, belong to their respective rights holders. This repository is intended for research, preservation, and technical understanding. No original ROM is provided. You are responsible for obtaining any required tools and game files legally and complying with applicable law.

## Credits

- **[Sinon-Hecate-II](https://github.com/Sinon-Hecate-II)** — project repository and decompilation work.
- **[ds-decomp](https://github.com/AetiasHax/ds-decomp)** — Nintendo DS decompilation tooling used by the project.
- **[ByteMatch](https://bytematch.dev/Sinon-Hecate-II/awdordc-decomp)** — public matching-progress tracking.
- **Nintendo / Intelligent Systems** — original game and intellectual property.

---

*This project is a work in progress; progress and build compatibility may change as the decompilation develops.*

# Side-Channel-Notebook

> [!WARNING]
> Work in progress

> [!NOTE]
> All the resources mentioned are ones I've studied/used, am currently studying or will be studying.

**Side-channel attacks *(SCA)*:**  An attack enabled by **leakage of information from a physical cryptosystem**. Characteristics that could be exploited in a side-channel attack include **timing, power consumption, and electromagnetic and acoustic emissions**. *[(Source)](https://csrc.nist.gov/glossary/term/side_channel_attack)*

## Types of Attacks on embedded system

> [!NOTE]
> This section is taken from "[The Hardware Hacking Book](#book-resources)"

There are tons of types of attack on embedded systems, and here's a list of some of them:

- **Software Attacks on Hardware**
    - **Fault Injection:** Practice of pushing hardware to a point that induces processing errors.
        - *DRAM Hammering*
        - *CPU overclocking*
    - **Side-Channel Attacks**
        - **Microarchitectural attacks**
- **PCB-Level Attacks**
- **Logical Attacks:** Attack at the level of logical interfaces.
- **Debugging and Tracing**
- **Fuzzing Devices:** The goal is to find crashes to exploit for code injection.
    - **Dump fuzzing:** Send random data to a target and observe its behavior.
    - **Smart fuzzing:** Focuses on protocols, data structures, typical crash-causing values, or code structure.
    - **Generation-based fuzzing:** Fuzzing that creates inputs from scratch.
    - **Mutation-based fuzzing:** Fuzzing that takes existing inputs and modifies them.
    - **Coverage-guided fuzzing:** Fuzzing that takes existing data to allow you to find deeper bugs.
- **Flash Image Analysis**

## Side-Channel Attacks (SCA)

As for hardware attacks, there're a large number of possible side-channel attacks. Here is a non-exhaustive list of SCA categories [(Source)](https://en.wikipedia.org/wiki/Side-channel_attack):
- **Cache attack**
- **Timing attack**
- **Power-monitoring attack**
- **Electromagnetic attack**
- **Acoustic cryptanalysis**
- **Differential fault analysis**
- **Data remanence**

## Difference between Side-channel attacks and  Invasive attacks

> [!NOTE]
> The information on this section are from [An Introduction to Mathematical Cryptography (Second Edition)](https://link.springer.com/book/10.1007/978-1-4939-1711-2)

- **Black-box model:** The attacker only sees what goes in and out of the cipher.
- **Gray-box model:** The attacks has access to a cipher implementation.

Both of this attacks believe in the **gray-box model**.

However, SCA are noninvasive, whereas invasive attacks are.

Invasive attacks are more powerful than SCA, but more expensive because they require sophisitacted equipment. They require tools such as a high-resolution microscopes and a chemical lab.

# Attacks implementation and labs

> [!NOTE]
> I find it very difficult to find free resources to perform SCA safely, which make the learning process longer, as we need theory and practice to fully understand SCA. That's why I would like to provide some practical labs, but it's going to take some time.
>
> However, if I find practical labs for certain attacks, I'll link to those resources as well.

- [ ] **Timing Attacks**
- [ ] **Website Fingerprinting**
- [ ] **Cache Attacks**
- [ ] **Spectre**
- [ ] **Meltdown**
- [ ] **Rowhammer**
- [ ] **ASLR Bypasses**
- [ ] **CPU Fuzzing**

# Web Resources

|                                                    **Name**                                                   |                                             **Type**                                             |       **Source**      |
|:-------------------------------------------------------------------------------------------------------------:|:------------------------------------------------------------------------------------------------:|:---------------------:|
|              [Side Channel Security](https://www.youtube.com/@SideChannelSecurity) *(All Season)*             |                                              Theory                                              |        TU Graz        |
| [Coursebook for attack on Implementation](https://orenlab.sise.bgu.ac.il/AttacksonImplementationsCourseBook/) | Theory / [Lab](https://github.com/Yossioren/AttacksonImplementationsCourseBook/tree/master/Labs) | Ben-Gurion University |
|                              [Secure Hardware Design](https://shd.mit.edu/2024/)                              |                 Theory / [Lab](https://github.com/CSAIL-Arch-Sec/SHD-StarterCode)                |          MIT          |
|                               [Hackropole](https://hackropole.fr/fr/challenges/)                              |                                                CTF                                               |         ANSSI         |
|                                        [Root-me](https://root-me.org/)                                        |                                                CTF                                               |        Root-Me        |
|                       [ASCAD](https://github.com/ANSSI-FR/ASCAD) *(ANSSI SCA Database)*                       |                                    Databases / Trained models                                    |         ANSSI         |

# Book Resources

- [The Hardware Hacking Book - *Breaking Embedded Security with Hardware Attacks*](https://nostarch.com/hardwarehacking)

# Resources not directly related to SCA but useful/necessary for understanding certain concepts/attacks

| **Name** | **Content** | **Type** |
|:--------:|:-----------:|:--------:|
| [MIT - Introduction to Deep Learning](http://introtodeeplearning.com/2023/) | Deep Learning | [Youtube](https://www.youtube.com/@AAmini) / [GitHub](https://github.com/aamini/introtodeeplearning) |
| [Artificial Intelligence: A Modern Approach, 4th Global ed.](https://aima.eecs.berkeley.edu/global-index.html) | AI textbook | Book |
| [A Journey in Creating an Operating System Kernel - 539kernel](https://539kernel.com/) | Operating System | Book |
| [The Fuzzing Project](https://fuzzing-project.org/) | Fuzzing | Website |

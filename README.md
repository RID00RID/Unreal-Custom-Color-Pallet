# Unreal Custom Color Palette

A plugin for Unreal Engine that makes it easy to use a unified color palette across your entire project.  
All team members will only choose colors from a pre-approved set, ensuring consistency in UI, materials, lighting, and other elements.

## Features

- **Enhanced Color Picker** with a palette tab  
  When selecting any color in the editor (Material, Widget, Actor, etc.), a convenient palette with preset colors appears (as shown in the screenshot).

- **Default Palette**  
  Includes basic colors: white, various shades of gray, orange, green, cyan, red, and more.

- **Support for Multiple Categories and Palettes**  
  In the project settings, you can create your own categories and color tables.

- **Configuration via Project Settings**  
  - Go to **Edit → Project Settings → Game → Color Palette Settings**  
  - Add new categories  
  - Fill colors using **TMap** (key — color name, value — Linear Color)  
  - Settings are saved in `DefaultGame.ini`

- **Export / Import** palettes for easy transfer between projects

- **Visual preview** of the selected color (Old / New)

## How to Use

1. Install the plugin into your project (copy the plugin folder to `Plugins/` or enable it via Epic Games Launcher).
2. Open **Project Settings → Color Palette Settings**.
3. In the **Registered Palettes** section, add your categories and fill in the color table.
4. When selecting any color in the Unreal Editor, the Color Picker will now show a tab with your palette.
5. Choose the desired color — it will be applied automatically.

## Screenshots

<img width="456" height="607" alt="color_picker" src="https://github.com/user-attachments/assets/d710e538-9bfc-49b4-a74b-6d0bbeab8f12" />
<img width="1918" height="1027" alt="project_settings" src="https://github.com/user-attachments/assets/6d661fb4-0fa6-4d73-8917-866aa23d9a53" />

## Who It's For

- Team development (UI/UX, game design, art)
- Projects where strict adherence to brand book and color harmony is important
- Any Unreal Engine 5 projects where you frequently need to select colors

## Installation

1. Download the repository or release.
2. Place the plugin folder in your project directory: `YourProject/Plugins/`.
3. Restart the Unreal Editor.
4. Enable the plugin in **Edit → Plugins** (if it didn’t enable automatically).

**Author:** RID00RID  
**GitHub:** https://github.com/RID00RID/Unreal-Custom-Color-Pallet

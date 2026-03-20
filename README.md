# nice-view-gem (llwt fork)

![Preview](https://github.com/m165437/nice-view-gem/blob/main/.github/assets/preview.jpg?raw=true)

### A sleek customization for the nice!view shield

This is a fork of [M165437/nice-view-gem](https://github.com/M165437/nice-view-gem) with the following additions:

- **Hammerbeam pixel art slideshow** on the peripheral screen (30 pieces by Collin Hodge, ~1 min each), selectable as an alternative to the original crystal animation
- **Battery level on peripheral** — the peripheral screen shows battery percentage alongside the connection icon instead of the "SIG" label
- **Configurable connection icon background** — the inverted rectangle behind BT/USB icons can be toggled off for a cleaner look
- Compatible with **ZMK v0.3** (use the `v0.3-patched` branch)

## Usage

Add this shield to your `config/west.yml`:

```yml
manifest:
  remotes:
    - name: zmkfirmware
      url-base: https://github.com/zmkfirmware
    - name: llwt
      url-base: https://github.com/llwt
  projects:
    - name: zmk
      remote: zmkfirmware
      revision: v0.3
      import: app/west.yml
    - name: nice-view-gem
      remote: llwt
      revision: v0.3-patched
  self:
    path: config
```

Then swap the default nice_view shield for nice_view_gem in your `build.yaml`:

```yml
---
include:
  - board: nice_nano_v2
    shield: corne_left nice_view_adapter nice_view_gem
  - board: nice_nano_v2
    shield: corne_right nice_view_adapter nice_view_gem
```

## Configuration

All upstream options are supported, plus additional options from this fork.

### Upstream options

| Option | Type | Description | Default |
| --- | --- | --- | --- |
| `CONFIG_NICE_VIEW_GEM_WPM_FIXED_RANGE` | bool | Use a fixed range for the WPM chart and gauge. Set to `n` for dynamic range. | y |
| `CONFIG_NICE_VIEW_GEM_WPM_FIXED_RANGE_MAX` | int | Maximum value for the fixed WPM range. | 100 |
| `CONFIG_NICE_VIEW_GEM_ANIMATION` | bool | Enable animation on the peripheral screen. Set to `n` to show a random static frame instead. | y |
| `CONFIG_NICE_VIEW_GEM_ANIMATION_MS` | int | Total animation/slideshow duration in milliseconds. | 960 (crystal) / 1800000 (slideshow) |
| `CONFIG_NICE_VIEW_WIDGET_INVERTED` | bool | Invert all display colors. | n |

### Fork additions

| Option | Type | Description | Default |
| --- | --- | --- | --- |
| `CONFIG_NICE_VIEW_GEM_ART_CRYSTAL` | bool | Use the original rotating crystal animation on the peripheral screen. | n |
| `CONFIG_NICE_VIEW_GEM_ART_SLIDESHOW` | bool | Use the hammerbeam pixel art slideshow on the peripheral screen. | y |
| `CONFIG_NICE_VIEW_GEM_OUTPUT_BACKGROUND` | bool | Show a filled background rectangle behind the BT/USB connection icon (original upstream behavior). | n |

To switch to the crystal animation, add to your `.conf`:

```conf
CONFIG_NICE_VIEW_GEM_ART_CRYSTAL=y
```

To restore the original inverted connection icon style:

```conf
CONFIG_NICE_VIEW_GEM_OUTPUT_BACKGROUND=y
```

## Credits

- [M165437](https://github.com/M165437) for the original nice-view-gem shield
- [Teenage Engineering TX-6](https://teenage.engineering/products/tx-6) for the UI design inspiration
- [Trixelized](https://trixelized.itch.io/) for the crystal pixel art
- [Collin Hodge](https://github.com/GPeye/hammerbeam-slideshow) for the hammerbeam pixel art
- [Jayvee Enaguas](https://github.com/jvne) for the Pixel Operator font ([CC0 1.0](https://creativecommons.org/publicdomain/zero/1.0/))

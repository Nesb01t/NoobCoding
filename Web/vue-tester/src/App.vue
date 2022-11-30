<template>
  <div class="app">
    {{ hello }}
  </div>
</template>

<script setup>
import { ref } from 'vue';

const hello = ref("hello world!")
</script>